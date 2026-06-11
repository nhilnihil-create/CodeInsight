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

int main(){cout<<fixed<<setprecision(20);
		  ll n,k;
           cin>>n>>k;
           vll a(n);
           rep(i,0,n)cin>>a[i];
           vector<P> cnt(n);
           rep(i,0,n){
            ll now=a[i];
             rep(j,0,n){
               if(i<j&&a[i]>a[j])cnt[i].first++;
               if(a[i]>a[j])cnt[i].second++;
             }
           }
           ll ans=0;
           rep(i,0,n){
              ans+=k*cnt[i].first;
               ans+=k*k%inf*cnt[i].second;
             ans-=k*(k+1)/2%inf*cnt[i].second;
               ans%=inf;
           }
           if(ans<0)ans+=inf;
           cout<<ans<<endl;
          }