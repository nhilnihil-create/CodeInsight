#include <bits/stdc++.h>
using namespace std; 

int main(){
  int N;
  cin >> N;
  long long sum=0;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int i=1;i<N;i++){
    if(A.at(i-1)>A.at(i)){
      sum+=A.at(i-1)-A.at(i);
      A.at(i)=A.at(i-1);
    }
  }
  cout << sum << endl;
}