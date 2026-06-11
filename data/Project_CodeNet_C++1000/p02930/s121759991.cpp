#include<cstdio>
#include<iostream>
#include<vector>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
inline char nc() {	
	return getchar();
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++; 
}
template<class T> void read(T &x) {
	x=0; int f=1,ch=nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x*=f;
}
const int maxn=500+5;
int N;
int c[maxn][maxn];
inline void adde(int u,int v,int w) {
	if(u>v) swap(u,v);
	c[u][v]=w;
}
void sol(vector<int> &v,int k) {
	if(v.size()==1) {
		return;
	}
	vector<int> t[2];
	for(unsigned int i=0;i<v.size();++i) {
		t[i&1].push_back(v[i]);
	}
	for(unsigned int i=0;i<t[0].size();++i) {
		for(unsigned int j=0;j<t[1].size();++j) {
			adde(t[0][i],t[1][j],k);
		}
	}
	sol(t[0],k+1);
	sol(t[1],k+1);
}
int main() {
	read(N);
	vector<int> v;
	for(int i=1;i<=N;++i) v.push_back(i);
	sol(v,1);
	for(int i=1;i<N;++i) {
		for(int j=i+1;j<=N;++j) {
			if(j!=i+1) printf(" ");
			printf("%d",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}