#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//monoid,結合律が成り立ち,単位元が存在するものに対しての演算をクエリに対してO(logn)で
//1-indexed  n(親)->2n,2n+1(子)  k(子)->k/2(親)
template<typename Monoid>
struct SegmentTree{
    using F = function< Monoid(Monoid, Monoid) >;
    //sz:size->完全二分木なのでszはnよりも大きい最小の2のべき乗数
    int sz;
    vector<Monoid> seg;
 
    const F f;
    const Monoid M1;
    SegmentTree(int n,const F f,const Monoid &M1) : f(f), M1(M1) {
 
    sz=1;
    while(sz<n) sz<<=1;
    seg.assign(2*sz, M1);
    }
 
    void set(int k, const Monoid &x){
        seg[k+sz] = x;
    }
 
    void build(){
        for(int k=sz-1;k>0;k--){
        seg[k]=f(seg[2*k+0], seg[2*k+1]);
        }
    }
 
    void update(int k,const Monoid &x){
        k+=sz;
        seg[k]=x;
        
    while(k>>=1){
        seg[k]=f(seg[2*k+0],seg[2*k+1]);
        }
    }
    //query聞くときは区間は[a,b)で(a<=x<b)
    Monoid query(int a, int b) {
        Monoid L=M1,R=M1;
        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1){
            if(a&1) L=f(L, seg[a++]);
            if(b&1) R=f(seg[--b], R);
        }
        return f(L,R);
    }   
    Monoid operator[](const int &k) const{
        return seg[k+sz];
    }
};
 
 
pair<ll,int> f(pair<ll,int> a,pair<ll,int> b){
    if(a.first>b.first){
        return a;
    }else{
        return b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    vector<ll> a(n),b(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];

    /*
    逆を考える
    bに関して
    a b cみたいなのがあって，b>=a+cの時，
    aとcに関してはbが大きいため絶対に操作できないし，
    操作できないから他のところの操作によりaとcの値が変わるかわることはない
    だからb>=a+cの関係が崩れるまで，or  bの値がa[i]にそろうまで
    bに関して操作を続けていい
    */

   //めんどくさいから最大値選ぶときにセグ木していい？
   //いいよ

    SegmentTree<pair<ll,int>> seg(n,f,make_pair(0,0));
    rep(i,n) seg.set(i,make_pair(b[i],i));
    seg.build();

    ll ans=0;
    int cnt_correct=0;
    while(true){
        auto tmp=seg.query(0,n);
        //cout<<"seg: "<<tmp.first<<' '<<tmp.second<<endl;
        int i=tmp.second;
        ll ryoutan=b[ (i+n-1)%n ] + b[ (i+1)%n ];
        // a[i]に揃えなきゃ
        ll diff=b[i]-a[i];
        ll times=diff/ryoutan;
        if(times==0&&(b[i]!=a[i])){
            cout<<-1<<endl;
            return 0;
        }
        ans+=times;
        b[i]-=ryoutan*times;
        

        if(a[i]==b[i]){
            cnt_correct++;
            seg.update(i,make_pair(-1,i));
        }else{
            seg.update(i,make_pair(b[i],i));
        }
        //debug(b);
        if(cnt_correct==n) break;
    }
    cout<<ans<<endl;
    return 0;
}
