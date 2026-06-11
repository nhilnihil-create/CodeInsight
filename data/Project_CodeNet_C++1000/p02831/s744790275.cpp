#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  if(a<b) swap(a,b);
  return a*b/gcd(a,b);
}
 
int main(){
  ll a, b;
  cin >> a >> b;
  ll ans = lcm(a, b);
  cout << ans << endl;
  return 0;
}
