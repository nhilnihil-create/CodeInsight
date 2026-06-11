#include <bits/stdc++.h>
using namespace std;

int main() {
  long double N,K;
  cin >> N >> K;
  vector<long double> V(N);
  for (int i = 0; i < N; i++)
    cin >> V.at(i);
  
  long double a = 0;
  for (int I = 0; I < K; I++) 
    a += V.at(I);
  
  long double count = a;
  long double maxcount = a;
    
  for (int j = 1; j < N - K + 1; j++) {
    count += V.at(j + K - 1) - V.at(j - 1);
    if (count > maxcount)
      maxcount = count;
  }
    
  long double ans = (maxcount + K)/2;  
   
  cout << fixed << setprecision(10);
  cout << ans << endl;
    
}
