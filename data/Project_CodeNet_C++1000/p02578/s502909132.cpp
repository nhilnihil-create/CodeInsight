#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  uint64_t sum=0;
  int m=0;
  int a;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a<m){
      sum+=m-a;
    }else{
      m=a;
    }
  }
  cout<<sum<<endl;
}
      