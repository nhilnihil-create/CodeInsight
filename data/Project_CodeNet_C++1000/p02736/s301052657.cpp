#include<bits/stdc++.h>
using namespace std;
int cnt[3];
int main(){
	int n;char ch;int f=0;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>ch,f=(ch=='2'?1:f),cnt[ch-'0'-1]+=(((n-1)&i)==i);
	if(cnt[1]&1) puts("1");
	else if(cnt[2]%2==1 && f==0) puts("2");
	else puts("0");
	return 0;
}