#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  int i=0;
  while(n/pow(k,i)>=1){
    i++;
  }
  cout<<i<<endl;
  return 0;
}