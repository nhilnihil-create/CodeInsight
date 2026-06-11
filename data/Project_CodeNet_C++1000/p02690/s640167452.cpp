#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll X; cin >> X;

  ll MAX = 200;
  for(ll A = -MAX; A <= MAX; A++){
    for(ll B = -MAX; B <= MAX; B++){
      if( pow(A,5) - pow(B,5) == X){
        cout << A << " " << B << endl;
        return 0;
      }
    }
  }
}
