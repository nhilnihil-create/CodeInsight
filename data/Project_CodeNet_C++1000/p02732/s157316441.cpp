#include <bits/stdc++.h>
using namespace std;
    
int main() {
  long long N;
  cin >> N;
  
  vector<long long> V(N);
  for (long long i = 0; i < N; i++)
    cin >> V.at(i);
   
  vector<long long> W(N,0);
  for (long long j = 0; j < N; j++)
    W.at(V.at(j) - 1)++;
  
  vector<long long> X(N);
  for (long long k = 0; k < N; k++)
    X.at(k) = W.at(V.at(k) - 1);
  
  long long sum = 0;
  for (long long l = 0; l < N; l++)
    sum += W.at(l)*(W.at(l) - 1)/2;
  
  for (long long m = 0; m < N; m++)
    cout << sum - X.at(m) + 1 << endl;
    
    
    
}
