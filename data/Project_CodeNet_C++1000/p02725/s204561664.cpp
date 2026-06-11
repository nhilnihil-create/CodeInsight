#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int K,N,minsum=1e9;
  cin >> K >> N;
  vector<int> A(2*N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    A.at(i+N)=A.at(i)+K;
  }
  for(int i=0;i<N;i++){
    int sum=0;
    sum=A.at(i+N-1)-A.at(i);
    minsum=min(minsum,sum);
  }
  cout << minsum << endl;
}      