#include<iostream>
using namespace std;

main(){
  long long n,s=0;
  cin>>n;
  for(int i=1;i<n+1;i++){
    if(i%3==0) continue;
    if(i%5==0) continue;
    s = s+i;
  }
  cout<<s<<endl;
  return 0;
}