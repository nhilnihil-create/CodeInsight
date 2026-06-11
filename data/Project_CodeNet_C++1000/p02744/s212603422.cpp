#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long LL;
const int MR=1e6+10;

int n;
char a[15]={};

void search(int p){
	if(p==n){
		a[p]=0;
		printf("%s\n",a);
		return;
	}
	char m=a[0];
	for(int i=1;i<p;i++) m=max(m,a[i]);
	for(a[p]='a';a[p]<=m+1;a[p]++){
		search(p+1);
	}
}

int main(){
	cin>>n;
	a[0]='a';
	search(1);
	return 0;
}