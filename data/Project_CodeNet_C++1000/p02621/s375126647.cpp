#include<iostream>
using namespace std;
 
int power(int a,int n){
  int res = 1;
  while(n){
    if(n%2){
      res = res * a;
      n--;
    }
    else{
      a = a*a;
      n/=2;
    }
  }
  return res;
}
 
int main(){
  int a;
  cin>>a;
  int aSq = power(a,2);
  int aCu = power(a,3);
  cout<< a+ aCu + aSq;
  return 0;
}