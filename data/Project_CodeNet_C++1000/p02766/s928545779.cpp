#include<iostream>
#include<stdio.h>
using namespace std;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)

const int mod=1000000007;


int main(){
int n,k;
cin>>n>>k;
int ans=0;
while(n>0){
  n/=k;
  ans++;
}
cout<<ans<<endl;
return 0;
}