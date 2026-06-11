#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int gi() {
	char ch='!'; int res=0, f=0;
	while(ch<'0' || ch>'9') { ch=getchar(); if(ch == '-') f=1; }
	while(ch>='0' && ch<='9') res=res*10+ch-'0', ch=getchar();
	return f?-res:res;
}
int n,a[N],c[3],o[3];
int main() {
	n=gi(); memset(c,-1,sizeof(c));
	for(int i=1;i<=n;++i) {
		a[i]=gi();
		for(int j=0;j<4;++j) {
			if(j == 3) { puts("No"); return 0; }
			if(a[i] == c[j]) { ++o[j]; break; }
			if(c[j] == -1) { c[j]=a[i], o[j]=1; break; }
		}
	}
	if(c[0] == 0 && o[0] == n) puts("Yes"), exit(0);
	if(c[2] == -1) {
		if(c[1] == -1) puts("No"), exit(0);
		if(c[0] == 0) swap(c[0],c[1]), swap(o[0],o[1]);
		if(c[1]) puts("No"), exit(0);
		if(c[1] == 0) {
			if(o[0] == o[1]*2) puts("Yes"), exit(0);
			puts("No"); exit(0);
		}
	}
	else {
		if(c[0]^c[1]^c[2]) puts("No"), exit(0);
		if(o[0] != o[1] || o[0] != o[2]) puts("No"), exit(0);
		puts("Yes");
	}
	return 0;
}