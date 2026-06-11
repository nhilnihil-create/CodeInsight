#include<stdio.h>
#include<iostream>

using namespace std;

int gcd(int,int);

int main(){
  int x,y;
  cin >> x >> y;
  cout << gcd(x,y) <<endl;
  return 0;
}

int gcd(int n,int m){
  int q,r;
  if(n<m){
    q=n;
    n=m;
    m=q;
  }  
  while(m>0){
    r=n%m;
    n=m;
    m=r;
  }
  return n;
}