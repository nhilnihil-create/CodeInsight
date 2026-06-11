#include<iostream>
#include<stdio.h>
using namespace std;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)

const int mod=1000000007;


int main(){
int a,b;
cin>>a>>b;
rep(pr,10000){
int za=pr*8/100;
int zb=pr*1/10;
if(za==a&&zb==b){
  cout<<pr<<endl;
  return 0;
}
}
cout<<-1<<endl;
return 0;
}