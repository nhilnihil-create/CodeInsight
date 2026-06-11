#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define G() Cr = getchar()
int Xr, Fr; char Cr;
inline int rd() {
	Xr =0 , Fr = 1, G();
	while(Cr < '0' || Cr > '9') {if(Cr == '-') Fr = -1; G();}
	while(Cr >='0' && Cr <= '9') Xr = (Xr<<1) + (Xr<<3) + (Cr&15), G();
	return Xr * Fr;
}
#define MAX_N 2005
#define LL long long
int n;
LL ans;
LL dp[MAX_N][MAX_N];
struct node {
	int pos;
	LL va;
}e[MAX_N];
bool comp(node x,node y) {
	return x.va < y.va;
}
int main() {
	n = rd();
	for(int i = 1; i <= n; i++) e[i].va = rd(), e[i].pos = i;
	sort(e+1,e+1+n,comp);
	for(int i = 1; i <= n; i++) {
		LL ma = e[i].va, t = e[i].pos;
		for(int l = 1, r = l + i - 1; r <= n; l++, r++)
			dp[l][r] = max(dp[l][r-1] + ma * abs(t - r), dp[l+1][r] + ma * abs(t - l));
	}
	cout<<dp[1][n]<<endl;
}