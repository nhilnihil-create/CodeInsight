#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> d(N);
  for(int i=0; i<N; i++){
    cin>>d.at(i);
  }
  int sum = 0;
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i<j){
        sum = sum+d.at(i)*d.at(j);
      }
    }
  }
  cout<<sum<<endl;
}