#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
   int n;
   cin >> n;
   queue<string>que;
   que.push("a");
   int p = 2;
   rep(i, 2, n+1){
       rep(j, 1, p){
           string s = que.front();
           que.pop();
           int i2 = 0;
           rep(k, 0, s.size()){
               i2 = max(i2,s[k]-'a');
           }
           rep(k, 0, i2+2){
               char temp = k + 'a';
               que.push(s+temp);
           } 
       }
       p = que.size()+1;
   }
   while(!que.empty()){
       cout << que.front() << endl;
       que.pop();
   }
   return 0;
}