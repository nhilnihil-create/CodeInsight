#include<bits/stdc++.h>
using namespace std;
  
int main(){
  long long N,K;
  cin >> N >> K;
  long long A=N/K;
  N-=A*K;
  cout << min(abs(N-K),N) << endl;
}
  