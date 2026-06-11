#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int i,N,X,sum=0;
  cin >> N;
  vector<int> vec(N);
  for(i=0;i<N;i++){
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  X=(double)sum/N+0.5;
  sum = 0;
  for(i=0;i<N;i++){
    sum += (vec.at(i)-X)*(vec.at(i)-X);
  }
  cout << sum << endl;
  
  return 0;
}