#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<map>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1e4;
const int mod=1e9+7;

typedef long long ll;

int q[maxn];

int main(){
	int n;cin>>n;
	q[0]=1;
	for(int i=3;i<=n;i++){
		q[i]=(q[i-1]+q[i-3])%mod;
	}
	cout<<q[n];
	return 0;
}