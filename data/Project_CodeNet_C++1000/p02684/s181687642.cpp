#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using lb=long double;
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
ll loop;
ll start;
ll last;
vll a;
ll dist[220000];

void f(ll now){
 ll next=a[now];
  if(dist[next]==-1){
    dist[next]=dist[now]+1;
    f(next);
  }
  else{
    start=dist[next];
    last=dist[now];
    loop=dist[now]-dist[next]+1;
  }
}

int main(){cout<<fixed<<setprecision(20);
		   ll n,k;
           cin>>n>>k;
           a.resize(n);
           rep(i,0,n){
             cin>>a[i];
             a[i]--;
           }
           rep(i,0,n)dist[i]=-1;
           dist[0]=0;
           f(0);
           if(last>=k){
            rep(i,0,n){
             if(dist[i]==k){
              cout<<i+1<<endl;
               return 0;
             }
            }
           }
           else{
            // cout<<start<<" "<<loop<<" "<<last<<endl;
             k-=start-1;
             k%=loop;
             k=(k+loop-1)%loop;
             //cout<<k<<endl;
             k+=start;
             rep(i,0,n){
              if(dist[i]==k){
               cout<<i+1<<endl;
                return 0;
              }
             }
           }
}