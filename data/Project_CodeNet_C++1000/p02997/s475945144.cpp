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
using vll=vector<ll>;
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
		   //中心1つ(1)の時が最大 (n-1)(n-2)/2
           //それ以下は全て可能？
           int n,k;
           cin>>n>>k;
           if(k>(n-1)*(n-2)/2){
            cout<<-1<<endl;
             return 0;
           }
           int m=0;
           int e=(n-1)*(n-2)/2;
           vector<P> ans(0);
           rep(i,0,n-1){
            ans.pb(mp(1,i+2));
            m++;
           }
           int to=3,from=2;
           while(k!=e){
            m++;
            e--;
            ans.pb(mp(from,to));
             to++;
             if(to==n+1){
               to=from+2;
               from++;
             }
           }
           cout<<m<<endl;
           rep(i,0,m){
            cout<<ans[i].first<<" "<<ans[i].second<<endl; 
           }
}