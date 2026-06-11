#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int f[210000];
int main(){
	cin>>n;
	int x;
	for(int i=1;i<n;++i){
		scanf("%d",&x);
		f[x]++;
	}
	for(int i=1;i<=n;++i)  printf("%d\n",f[i]);
	return 0;
}


