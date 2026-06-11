#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
  int K, N;
  cin >> K >> N;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  A.push_back(A[0]+K);
  
  int l = 0;
  for(int i = 0; i < N; ++i)
  {
    l = max(l, A[i+1]-A[i]);
  }
  
  cout << K-l << endl;
}