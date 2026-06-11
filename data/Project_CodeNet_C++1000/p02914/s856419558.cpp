#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

// Aを変形してBにできるか <=> AとBの標準形が一致するか
struct BinaryBasis{
    vector<ll> basis;
    bool update;
    BinaryBasis():update(false){}
    // 基底に加える
    bool add(ll bit){
        for(auto &p:basis) bit=min(bit,bit^p);
        if(bit){
            basis.push_back(bit);
            return update=true;
        }
        else return false;
    }
    // bitを基底で表現できるか
    bool check(ll bit){
        for(auto &p:basis) bit=min(bit,bit^p);
        return bit==0;
    }
    // 掃き出して標準形に
    void normalize(){
        if(update){
            sort(begin(basis),end(basis));
            update=false;
        }
        for(int i=(int)basis.size()-1;i>=0;i--){
            for(int j=i-1;j>=0;j--) basis[i]=min(basis[i],basis[i]^basis[j]);
        }
    }
    bool operator==(BinaryBasis &a){
        normalize(),a.normalize();
        return basis==a.basis;
    }
    // 0-indexedでk番目を返す
    ll get_kth(ll k){
        if((1ll<<basis.size()<=k)) return -1;
        ll ret=0;
        if(update){
            sort(begin(basis),end(basis));
            update=false;
        }
        for(int i=(int)basis.size()-1;i>=0;i--){
            if(k<(1ll<<i)) ret=min(ret,ret^basis[i]);
            else{
                k-=1ll<<i;
                ret=max(ret,ret^basis[i]);
            }
        }
        return ret;
    }
 
    size_t size() const{
        return basis.size();
    }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    // 奇数個1な桁は考慮したくないから最初に省く

    int n;cin>>n;
    ll t=0;
    vector<ll> v(n);
    rep(i,n){
        cin>>v[i];
        t^=v[i];
    }
    ll ans=0;
    rep(i,60){
        if((t>>i)&1){
            ans+=1ll<<i;
            rep(j,n){
                if((v[j]>>i)&1)v[j]^=(1ll<<i);
            }
        }
    }

    BinaryBasis bs;
    rep(i,n) bs.add(v[i]);
    bs.normalize();
    ll a=0;
    for(auto b:bs.basis) chmax(a,a^b);
    a<<=1;
    ans+=a;
    cout<<ans<<endl;
    return 0;
}
