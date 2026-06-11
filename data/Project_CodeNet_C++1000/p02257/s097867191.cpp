#include<bits/stdc++.h>
using namespace std;
bool Prime(long long n);
main(){
  int n;
  int cnt=0;
  long long a;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a;
    if(Prime(a)){
      cnt++;
    }
  }
  cout<<cnt<<endl;
}
bool Prime(long long n){
  if(n==2){
    return true;
  }
  else if(2>n||n%2==0){
    return false;
  }
  else{
    for(int i=3;i<=sqrt(n);i+=2){
      if(n%i==0){
	return false;
      }
    }
    return true;
  }
}