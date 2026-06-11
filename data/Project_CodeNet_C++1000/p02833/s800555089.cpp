#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  if(n%2) ans = 0;
  else{
    ll tmp = 5;
    while(n>=tmp){
      ans += n/tmp/2;
      tmp *= 5;
    }
  }
  cout << ans << endl;
  return 0;
}
