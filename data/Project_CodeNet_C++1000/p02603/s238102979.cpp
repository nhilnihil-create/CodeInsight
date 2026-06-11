#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long int N, MONEY = 1000;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++){
	cin >> A.at(i);
  }
  
  for (int i = 0; i < N - 1; i++){
    
    if (A.at(i) < A.at(i + 1)){
      long long int KAB = MONEY / A.at(i);
      MONEY += (A.at(i + 1) - A.at(i)) * KAB;
    }
    
  }
  
  cout << MONEY << endl;
}