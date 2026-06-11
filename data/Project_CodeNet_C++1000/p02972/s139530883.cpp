#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Z=0;
  cin>>N;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p.at(i);
  }
  vector<int> q(N);
  for(int i=N-1;i>=0;i--){
    int A=0;
    for(int j=i*2+1;j<N;j+=i+1){
      A+=q.at(j);
    }
    if((A+p.at(i))%2==1){
      q.at(i)=1;
      Z++;
    }
  }
  cout<<Z<<endl;
  for(int k=0;k<N;k++){
    if(q.at(k)==1){
      cout<<k+1<<endl;
    }
  }
}