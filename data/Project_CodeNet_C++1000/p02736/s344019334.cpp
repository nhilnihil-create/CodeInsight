#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,flag,a[1000010],b[1000010];
char s[1000010];
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	for(i=0;i<n;i++){
		a[i]=s[i]-'1';
		if(a[i]==1)flag=1;
		b[a[i]]+=(((n-1)&i)==i);
	}
	if(b[1]&1)puts("1"); 
	 else if(!flag&&b[2]&1)puts("2");
	  else puts("0");
}