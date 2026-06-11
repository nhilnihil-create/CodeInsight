#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  while(n>0){
int rem = n%10;
    if(rem==7){
      cout<<"Yes\n";
      return 0;
    }
      
    n/=10;
  }
  cout<<"No\n";
}