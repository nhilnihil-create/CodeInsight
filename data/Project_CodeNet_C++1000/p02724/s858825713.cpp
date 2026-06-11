#include<iostream>
#include<stdio.h>
using namespace std;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)

const int mod=1000000007;


int main(){
  int x;
  int a,b,c;
  cin>>x;
  a=x/500;
  c=x%500;
  b=c/5;
  cout<<1000*a+5*b<<endl;
  return 0;
}