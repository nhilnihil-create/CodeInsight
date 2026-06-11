#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 200000;

int R[MAX], N;

main(){
  cin >> N;
  for (int i = 0; i < N; i++ ) cin >> R[i];
  
  int minv =R[0];
  int ans =-2000000000;

  for ( int i=1; i<N; i++ ){
    ans = max(ans, R[i] - minv);
    minv = min(minv, R[i]);
  }

  cout << ans << endl;
}