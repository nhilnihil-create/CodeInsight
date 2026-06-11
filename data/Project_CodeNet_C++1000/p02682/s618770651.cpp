#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll A,B,C,K; cin >> A >> B >> C >> K;

  if(K <= A){
    cout << K << endl;
    return 0;
  } else if(K <= A + B ){
    cout << A << endl;
  } else {
    ll tmp = K - (A+B);
    cout << A - tmp << endl;
  }

}
