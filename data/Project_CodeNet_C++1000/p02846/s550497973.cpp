#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  ll T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2;
  cin >> A1 >> A2;
  cin >> B1 >> B2;

  ll V1 = A1 - B1;
  ll V2 = A2 - B2;

  if((V1>0 && V2>0) || (V1<0 && V2<0)){
    cout << 0 << endl;
  }
  else if(V1*T1 + V2*T2 == 0){
    cout << "infinity" << endl;
  }
  else {
    if(V1<0 && V2>0){
      V1 *= -1;
      V2 *= -1;
    }
    ll W1 = V1 * T1;
    ll W2 = V1 * T1 + V2 * T2;

    if(W2 > 0){
      cout << 0 << endl;
    }
    else if(W2 + W1 < 0){
      cout << 1 << endl;
    }else{
      ll cnt = W1/abs(W2);
      cnt *= 2;
      if(W1%W2==0) cnt--;
      cnt += 1;
      cout << cnt << endl;
    }
  }
  
  
  return 0;
}

