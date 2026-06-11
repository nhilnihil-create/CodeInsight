#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
typedef long long ll;

int main(){

  int N; cin >> N;

  vector <int> A(N);
  int ans = 0, Q = 0;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    ans += abs(A[i]);

    if (A[i] < 0) Q++;
  }
  sort(A.begin(), A.end());


  if (Q != 0 && Q != N){
    cout << ans << endl;
  }else if(Q == 0){
    cout << ans - 2 * A[0] << endl;
    Q++;
  }else if(Q == N){
    cout << ans + 2 * A[N - 1] << endl;
    Q--;
  }

  int now = A[0];
  for (int i = Q; i < N - 1; i++){
    cout << now << " " << A[i] << endl;
    if (i != N - 1) now = now - A[i];
  }
  
  for (int i = 0; i < Q; i++){
    if (i == 0){
      cout << A[N - 1] << " " << now << endl;
      now = A[N - 1] - now;
    }else{
      cout << now << " " << A[i] << endl;
      now = now - A[i];
    }
  }
  

    

  return 0;
}
