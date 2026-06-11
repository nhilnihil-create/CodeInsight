#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;
using G = vector<map<int, int>>;

int 
main() {

  ll A, B, X; cin >> A >> B >> X;
  if(B > X){
    cout << (A * X) / B << endl;
    return 0;
  } else if(B == X){
    --X;
    cout << (A * X) / B << endl;
    return 0;
  }

  ll ans = X / B;
  if(ans > 1){
    --ans;
    cout << ((A * ans) / B) - (A * (ans / B)) << endl;
  } else{
    ans = B - 1;
    cout << ((A * ans) / B) - (A * (ans / B)) << endl;
  }


  return 0;

}