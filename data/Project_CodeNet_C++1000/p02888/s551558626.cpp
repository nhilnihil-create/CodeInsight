#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (ll i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using ld=long double;
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

vin l;


bool check(int a,int x){
  //l[i]<l[j]+l[x]ならtrue
  return a<l[x];
}

int main(){cout<<fixed<<setprecision(20);
		   int n;
           cin>>n;
           l.resize(n);
           rep(i,0,n)cin>>l[i];
           sort(all(l));
           reverse(all(l));
           ll ans=0;
           rep(i,0,n-1){//1本目
            rep(j,i+1,n){//2本目
              int a=l[i]-l[j];
              int ok=j;
              int ng=n;
              while(ng-ok>1){
                int mid=(ok+ng)/2;
                if(check(a,mid))ok=mid;
                else ng=mid;
              }
              ans+=ok-j;
            }
           }
           cout<<ans<<endl;
}