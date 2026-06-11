#include<bits/stdc++.h>
using namespace std;

const int maxn=200009;

int n;
int a[maxn];
int sum;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)sum^=a[i];
	for(int i=1;i<=n;++i)printf("%d ",sum^a[i]);
	printf("\n");
	return 0;
}