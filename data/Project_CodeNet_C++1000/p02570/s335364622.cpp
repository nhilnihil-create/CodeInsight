#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll, ll> P;

struct edge {int to, cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

ll GCD(ll a, ll b){
  if(b==0) return a;
  else return GCD(b, a%b);
}

ll LCM(ll a, ll b){
  if(a<b) swap(a,b);
  return a/GCD(a,b)*b;
}

int main(){
  int d, t, s;
  cin >> d >> t >> s;
  string ans;
  if(d>t*s) ans = "No";
  else ans = "Yes";
  cout << ans << endl;
  return 0;
}
