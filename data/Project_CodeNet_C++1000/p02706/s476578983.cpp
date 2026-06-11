#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
using namespace std;
#define ll (long long)
#define PI (acos(-1))

int main()
{
  int N,M;
  cin >> N >> M;

  vector<int> A(M);

  int sum = 0;
  for(int i=0; i<M; i++){
    cin >> A[i];
    sum += A[i];
  }

  if(N < sum){
    cout << -1;
  }else{
    cout << N-sum;
  }
}
