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
string s,t;
cin>>n>>s>>t;
rep(i,n){
  cout<<s[i]<<t[i];
}
cout<<endl;
}

