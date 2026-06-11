#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll x,y; cin >> x >> y;
  // a+b = x, 2a * 4b = y

  for(ll a = 0; a <= 200; a++){
    for(ll b = 0; (y - 2 * b >= 0 ) && (x - b >= 0); b++){
      if(2 * a + 4 * b == y && a + b == x){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
