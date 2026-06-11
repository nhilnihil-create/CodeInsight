# include <iostream>
using namespace std;
typedef long long ll;

ll min(ll a, ll b, ll c){
  return min(a, min(b,c));
}

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans;
  if(a%2 == b%2) ans = (b-a)/2;
  else{
    ans = min(a-1, n-b) + 1 + (b-a-1)/2;
  }
  cout << ans << endl;
  return 0;
}