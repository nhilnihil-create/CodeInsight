#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  for(int i=0;i<N;i++) cin >> X.at(i);
  
  int min_tmp = 100000000;
  for(int i=1;i<=100;i++){
    int sum_tmp = 0;
    for(int j=0;j<N;j++){
      sum_tmp += (X.at(j)-i)*(X.at(j)-i);
    }
    if(min_tmp > sum_tmp ) min_tmp = sum_tmp;
  }
  cout << min_tmp << endl;
}