#include<iostream>
#include<stdio.h>
using namespace std;
using ll=long long;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)
using P=pair<int,int>;
const int mod=1000000007;


int main(){
  int n;
  int a[100];
cin>>n;
rep(i,n)cin>>a[i];
bool ok=true;
rep(i,n){
  if(a[i]%2==0&&a[i]%3!=0&&a[i]%5!=0){
    ok=false;
  }
}
if(ok)cout<<"APPROVED"<<endl;
else cout<<"DENIED"<<endl;
return 0;
}