#include <iostream>
using namespace std;
#define MAX 200010
int main(){
  int N,r[MAX],min[MAX],max[MAX];
  cin >> N;
  for(int i = 0; i < N ;i++){
    cin >>r[i];
  }
  min[0] = r[0];
  for(int i = 1; i < N; i++){
    if( r[i] < min[i-1] ) min[i] = r[i];
    else min[i] = min[i-1];
  }
  max[N-1] = r[N-1];
  for(int i = N-2; i >= 0; i--){
    if( r[i] > max[i+1] ) max[i] = r[i];
    else max[i] = max[i+1];
  }
  int ans = max[1]-min[0];
  for(int i = 0; i < N-1; i++){
    if(ans < (max[i+1]-min[i]) ) ans = max[i+1]-min[i];
  }
  cout << ans << endl;
  return 0;
}