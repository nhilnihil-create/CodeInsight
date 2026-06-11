#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  ll A[N];
  ll X[N];
  ll sum = 0;
  ll sum2 = 0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    sum += A[i];
    if(i%2==1 && i>0) sum2 += A[i];
  }
  X[0] = sum - 2*sum2;
  for(int i=1;i<N;i++){
    X[i] = 2*A[i-1] - X[i-1];
  }
  for(int i=0;i<N;i++){
    cout << X[i] << " ";
  }
  cout << endl;
}
