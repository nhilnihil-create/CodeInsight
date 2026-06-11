//bit全探索
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


int main(){cout<<fixed<<setprecision(10);
		   //greedy　後ろから決めていく 選べる中で最大のものを選ぶ
           int n,m;
           cin>>n>>m;
           vector<P> a(n);
           rep(i,0,n)cin>>a[i].first>>a[i].second;
           ll ans=0;
           rep(i,0,n){
             a[i].first=m-a[i].first;//いつまで選べるか
           }
           sort(all(a));
           reverse(all(a));
           int date=m-1;
           priority_queue<int, vector<int>, less<int>> pq;
           int i=0;
           while(true){
             while(i<n&&date<=a[i].first){
               pq.push(a[i].second);
               i++;
              // cout<<1<<endl;
             }
             if(!pq.empty()){
              ans+=pq.top();
               pq.pop();
             }
               date--;
             if(date==-1)break;
           }
           cout<<ans<<endl;
}