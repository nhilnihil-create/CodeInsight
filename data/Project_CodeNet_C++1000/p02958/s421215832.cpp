#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <math.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
typedef long long ll;
 
vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];
ll gcd(ll a, ll b)
{
   if (b == 0)
   {
       return a;
   }
    return gcd(b, a%b);
}
void dfs(int now, ll d) {
  visited[now] = true;
  dist[now] = d;
  for (auto p : to[now]) {
    if (visited[p.first]) continue;
    dfs(p.first, d + p.second);
  }
}
vector<int>ans(10005,0);
void f(ll n){
    for (ll x = 1; x*x<n;x++){
        for (ll y = 1; y*y<n;y++){
            for (ll z = 1; z*z<n;z++){
                ll v = (x*x)+(y*y)+(z*z)+(x*y)+(y*z)+(z*x);
                if(v<10005) ans[v]++;
            }
        }
    }
}
int find(ll k) {
    ll tag = 7777777;
    int cnt = 0;
    cout << tag%k << endl;
    while (tag%k) {
        cnt++;
        tag/=10;
        cout << tag << endl;
        
    }
    return cnt;
}
 
int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    int k = 0;
    rep(i,0,n) {
        cin >> p[i];
    }
    rep(i,0,n) {
        if(p[i] != i+1) k++;
    }
    if(k<=2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
