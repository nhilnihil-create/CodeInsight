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
int a,b;
cin>>a>>b;
if(a<=b)rep(i,b)cout<<a;
else rep(i,a)cout<<b;
return 0;
}

