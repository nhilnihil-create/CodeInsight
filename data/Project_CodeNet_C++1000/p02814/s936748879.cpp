#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vvin=vector<vin>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int n,m;
bool check( vin &a){
 bool ans=true;
  int q=-1;
  rep(i,0,n){
   int x=a[i];
    int cnt=0;
    while(x%2==0){
     cnt++;
      x/=2;
    }
    if(q==-1)q=cnt;
    else{
     if(q!=cnt)ans=0; 
    }
  }
  return ans;
}

ll lcm(ll a,ll b){
 return a/__gcd(a,b)*b; 
}

int main(){cout<<fixed<<setprecision(20);
           /*
           b[i]=a[i]/2;
           X=2*b[i](p+1/2)
           X=b[i]*(2p+1)
           (2p+1)==1以上の奇数
           Xはb[i]の公倍数かつ　2の素因数の数は全てのb[i]に等しい
           b[i]の2の素因数が全て等しいことが必要
           */
           cin>>n>>m;
           vin a(n);
           rep(i,0,n){
            cin>>a[i];
             a[i]/=2;
           }
           if(!check(a)){
             cout<<0<<endl;
             return 0;
           }
           ll l=1;
           rep(i,0,n){
             l=lcm(l,a[i]);
             if(l>m){
              cout<<0<<endl;
               return 0;
             }
           }
           ll ans=0;
           ans++;
           ans+=(m-l)/(2*l);
           cout<<ans<<endl;
}