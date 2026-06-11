#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
typedef pair<int,int> P;
struct edge{int to, id;};
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000
 
ll solve(ll n){
    if(n == 1) return 1;
    else if(n > 1){
        //return 1+solve(n/2) * 2;
      if(n % 2 ==0) return 1+solve(n/2) * 2;
      else return 1+solve((n-1)/2) * 2;
    }
}
 
 int main(){
     ll n;
     cin >> n;
     ll ans = solve(n);
     cout << ans << endl;
 
 }