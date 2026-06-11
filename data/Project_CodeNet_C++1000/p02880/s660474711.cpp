#include<iostream>
#include<stdio.h>
using namespace std;
using ll=long long;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)
using P=pair<int,int>;

//auto

int main(){
int n;
cin>>n;
bool ok=false;
for(int i=1;i<=9;i++){
  for(int j=1;j<=9;j++){
    if(n==j*i)ok=true;
  }
}
if(ok)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}

