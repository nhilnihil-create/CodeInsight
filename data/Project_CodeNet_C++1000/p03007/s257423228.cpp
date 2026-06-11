#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9


int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }
  int maxa = -INF, mina = INF, sum = 0;
  REP(i, N){
    maxa = max(maxa, A[i]);
    mina = min(mina, A[i]);
    sum += abs(A[i]);
  }
  vector<int> plus, minus;
  REP(i, N){
    if(A[i] > 0){
      plus.push_back(A[i]);
    }
    else if(A[i] < 0){
      minus.push_back(A[i]);
    }
    else{
      plus.push_back(A[i]);
    }
  }

  if(maxa < 0 || (plus.size() == 1)){
    if(maxa < 0) sum += maxa * 2;
    cout << sum << endl;
    sort(A.begin(), A.end());
    REP(i, N-1){
      cout << maxa << " " << A[i] << endl;
      maxa = maxa - A[i];
    }
  }
  else if(mina >= 0 || (minus.size() == 1)){
    if(mina > 0) sum -= mina * 2;
    cout << sum << endl;
    sort(A.begin(), A.end());
    if(N == 2){
      cout << A[1] << " " << A[0] << endl;
    }
    else{
      FOR(i, 1, N-1){
        cout << mina << " " << A[i] << endl;
        mina = mina - A[i];
      }
      cout << A[N-1] << " " << mina << endl;
    }
  }
  else{
    cout << sum << endl;
    int p = minus[0];
    FOR(i, 1, plus.size()){
      cout << p << " " << plus[i] << endl;
      p -= plus[i];
    }
    int m = plus[0];
    FOR(i, 1, minus.size()){
      cout << m << " " << minus[i] << endl;
      m -= minus[i];
    }
    cout << m << " " << p << endl;
  }
  

  return 0;
}
