#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> vec(N,0);
  vector<int> order(N,0);
  for(int i=0; i<N; i++){
    cin>>vec.at(i);
  }
  for(int i=0; i<N; i++){
    order.at(vec.at(i)-1)=i+1;
  }
  for(int i=0; i<N-1; i++){
    cout<<order.at(i)<<' ';
  }
  cout<<order.at(N-1)<<endl;
  
}
  