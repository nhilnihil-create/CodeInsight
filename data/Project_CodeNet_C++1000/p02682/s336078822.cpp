#include<iostream>
#include<stdio.h>
using namespace std;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)

const int mod=1000000007;


int main(){

int a,b,c,k;
cin>>a>>b>>c>>k;
if(a>=k) cout<<k;
else if(k<=a+b)cout<<a<<endl;
else if(k<=a+b+c) cout<<a-(k-a-b)<<endl;
return 0;
}