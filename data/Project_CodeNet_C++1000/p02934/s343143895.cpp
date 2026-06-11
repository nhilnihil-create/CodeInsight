#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<long double> A(N);
  long double gyakusuu;
  long double wa=0;
  
  for(int i=0; i<N ;i++){
    cin >> A.at(i);
    gyakusuu = 1/A.at(i);
    wa = wa + gyakusuu;
  }
  
  cout << fixed << setprecision(10);
  
  cout << 1/wa << endl;
  
}

