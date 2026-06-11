#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++){
    cin >> A[i];
  }
  int ma = A[0];
  long long sum = 0;
  for (int i=0; i<N; i++){
    ma = max(ma,A[i]);
    long long sub = ma - A[i];
    sum += sub;
  }
  cout << sum << endl;
}
   