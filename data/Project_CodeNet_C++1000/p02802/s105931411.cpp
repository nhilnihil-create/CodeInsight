#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;
ll dp[110][100100];
 
int main(){
   int n,m;
   cin >> n >> m;
   int ans = 0;
   vector<bool>ok(n,false);
   vector<int>pena(n,0);
   rep(i,m){
        int p;
        string  s;
        cin >> p >> s;
        p--;
        if(ok[p])continue;
        if(!ok[p]){
           if(s=="AC"){
              ans++;
              ok[p]=true;
           }
           if(s=="WA")pena[p]++;
        }
        
   }
   int cnt = 0;
   rep(i,n){
      if(ok[i])cnt+=pena[i];
   }
   cout << ans << ' ' <<cnt <<endl;
}