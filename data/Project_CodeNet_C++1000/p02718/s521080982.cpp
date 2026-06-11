#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main() {
  int N, M;
  float A[110];
  float sum = 0;
  int c = 0;
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
  }
  sort(A, A+N, greater<int>());
  for(int i = 0; i < N; i++){
    if(A[i] >= (float)sum/(4*M)) c++;
  }
  if(c >= M) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
