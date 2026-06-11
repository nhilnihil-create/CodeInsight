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
		   //gから貪欲
           int n,m;
           string s;
           cin>>n>>m>>s;
           reverse(all(s));
           vin ans(0);
           int now=0;
           while(now<n){
             int last=-1;
             rep(i,1,m+1){
               if(now+i<n+1&&s[now+i]=='0')last=now+i;
             }
             //cout<<now<<endl;
             ans.pb(last-now);
             now=last;
             if(last==-1){
              cout<<last<<endl;
               return 0;
             }
           }
           reverse(all(ans));
           int k=ans.size();
           rep(i,0,k)cout<<ans[i]<<" ";
}