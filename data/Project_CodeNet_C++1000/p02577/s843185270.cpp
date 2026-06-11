#include<iostream>
#include<stdio.h>
using namespace std;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)

const int mod=1000000007;


int main(){
char s[200010];
scanf("%s",s);
int len=strlen(s);
int sum=0;
rep(i,len)sum+=s[i]-'0';
if(sum%9==0)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}