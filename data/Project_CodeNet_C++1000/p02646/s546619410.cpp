#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll a,b,v,w;
  cin >> a >> v;
  cin >> b >> w;
  ll t; cin >> t;

  string ans;
  if(v < w){
    ans = "NO";
  } else {
    if(abs(a-b) > abs(v-w) * t){
      ans = "NO";
    } else {
      ans = "YES";
    }
  }
  cout << ans << endl;
}
