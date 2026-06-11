#include<bits/stdc++.h>
#define ll long long 
#define MAXN 200010
using namespace std;

int n,m;

struct node{
	int pos;
	int index;
}X[100010];

bool cmp(node a,node b){
	return a.pos<b.pos;
} 

int main(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		X[i].pos=x;
		X[i].index=i;
	}
	sort(X+1,X+1+n,cmp);
	for(int i=1;i<=n;i++){
		printf("%d ",X[i].index);
	}
//	printf("\n");
} 