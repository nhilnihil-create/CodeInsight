#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int N,M,count=0,sum=0;
  cin >> N >> M;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    sum+=A.at(i);
  }
  double K=sum/(4.0*M);
  for(int i=0;i<N;i++){
    if(A.at(i)>=(double)K){
      count++;
    }
  }
  if(count>=M){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
      
  