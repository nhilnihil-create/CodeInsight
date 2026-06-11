#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;
/*
const ll MAX_N=(1<<19);

ll n,nn,dat[2*MAX_N-1];//nn...segmenttreeの葉の大きさ,n...与えられた数列等の大きさ
ll a[1000000];

ll unit(){
    return 0;//単位元
}

ll calc(ll a,ll b){
    return a+b;//演算
}

//初期化
void init(){
    nn=1;
    while(nn<n) nn*=2;//座標とかであれば n<N ではなく n<(座標の最大値)　下も同様
    //for(int i=0;i<n;i++) dat[i+nn-1]=a[i];
    //for(int i=n;i<nn;i++) dat[i+nn-1]=unit();//単位元で埋める
}

void update(ll k,ll s){
    k+=nn-1;
    dat[k]=s;//変更する式
    while(k>0){
        k=(k-1)/2;
        dat[k]=calc(dat[2*k+1],dat[2*k+2]);//条件
    }
}

ll query(ll a,ll b,ll k,ll l,ll r){
    if(r<=a||b<=l) return unit();//単位元
    if(a<=l&&r<=b) return dat[k];

    ll m=(l+r)/2;
    ll u=query(a,b,2*k+1,l,m);
    ll v=query(a,b,2*k+2,m,r);
    return calc(u,v);//条件
}
*/

ll dp[10005];
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    //ll n;
    /*cin>>n;
    string s;
    cin>>s;
    reverse(all(s));
    ll cnt=0;
    ll t=1,tt=1;
    V<ll> at(n),att(n),st(n+1,0),stt(n+1,0);
    
    //init();
    rep(i,n){
        if(s[i]=='1')cnt++;
        //update(i,s[i]-'0');
    }
    rep(i,n){
        at[i]=t;
        att[i]=tt;
        t=(t*2)%(cnt-1);
        tt=(tt*2)%(cnt+1);
        st[i+1]=(st[i]+(ll)(s[i]-'0')*at[i])%(cnt-1);
        stt[i+1]=(stt[i]+(ll)(s[i]-'0')*att[i])%(cnt+1);
    }
    cout<<"ok"<<endl;

    rep(i,n){
        int ans=0;
        ll x,y,z;
        if(s[i]=='1'){
            x=at[i];
            y=st[n];
            z=cnt-1;
            y-=x;
        }
        else{
            x=att[i];
            y=stt[n];
            z=cnt+1;
            y=(y+x)%z;
        }
        ans++;
        while(y<0)y+=z;
        while(true){

            ll cc=0;
            ll xx=y;
            while(xx!=0){
                if(xx%2==1)cnt++;
                xx/=2;
            }
            if(y%cc==0) break;
            y=y%cc;
            ans++;
        }
        cout<<ans<<'\n';
    }*/
  	ll h,n;
  cin>>h>>n;
  V<ll> a(n),b(n);
  rep(i,n)cin>>a[i]>>b[i];
  for(int i=0;i<h;i++)dp[i]=INF;
  for(ll i=h;i>=0;i--){
    for(int j=0;j<n;j++){
      ll x=max(0LL,i-a[j]);
      chmin(dp[x],dp[i]+b[j]);
    }
  }
  cout<<dp[0]<<endl;
}
//ペナルティ出しても焦らない　ACできると信じろ！！！
//どうしてもわからないときはサンプルで実験　何か見えてくるかも
//頭で考えてダメなら紙におこせ！！
/*
V,P(大文字)使用不可
乗算などの際にオーバーフローに注意せよ！
(適切にmodをとれ　にぶたんで途中で切り上げろ)
制約をよく読め！
{
    ・全探索できるなら全探索しろ
    ・異常な制約ならそこに注目
}
stringの計算量(扱い)注意
コーナー注意！(特に数値が小さいものについては要検証)
N行出力のときは'¥n'
グリッド上では行先が範囲内におさまるかif文で確認(RE注意)
if文ではちゃんと比較演算子==を使え('='でもエラー出ない)
配列(vector)の大きさが0か1以上かで場合分けせよ(RE注意)
(vector<int> a(m)でm==0というものはできない)
modはなるべく最後に取れ！
doubleを扱うときには(abs)ではなく'fabs'!!!
*/