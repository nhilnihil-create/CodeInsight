#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,k=0;
  long long sum=0;
  cin >> N;
  vector<int> length(N);
  
  for(int i=0; i<N; i++)
    cin >> length.at(i);
  
  for(int j=0; j<N-1; j++){
    if(length.at(j)>length.at(j+1)){
      k=length.at(j+1);
      length.at(j+1)=length.at(j);
      sum += length.at(j)-k;
    }
  }
  
  cout << sum << endl;
  
}