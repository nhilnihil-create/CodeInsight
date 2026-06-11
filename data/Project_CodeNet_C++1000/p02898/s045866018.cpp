#include <bits/stdc++.h>
using namespace std;



int main(){
  int N,K;
  cin>>N>>K;
  
  vector<int> vec(N);
  int sum=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a>=K) sum++;
  }
  cout<<sum<<endl;
    
    
    
}