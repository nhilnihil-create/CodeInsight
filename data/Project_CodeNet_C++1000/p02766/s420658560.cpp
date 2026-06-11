#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,k;
  cin>>n>>k;
  int count=0;
  while(n>=1){
    n/=k;
    count++;
  }
  cout<<count<<endl;
}
    
    
    
