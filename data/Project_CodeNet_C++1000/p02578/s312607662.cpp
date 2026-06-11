#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0 ; i<N ; i++)
    cin >> A.at(i);
  
  vector<int> height(N-1);
  for (int i=0 ; i<N-1 ; i++){
    if (A.at(i) > A.at(i+1)){
      height.at(i) = A.at(i) - A.at(i+1);
      A.at(i+1) = A.at(i);
    }
    else
      height.at(i) = 0;
  }
  
  long long s = 0;
  for (int i=0 ; i<N-1 ; i++)
    s += height.at(i);
  
  cout << s << endl;
}