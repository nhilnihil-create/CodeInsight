#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 2010
using namespace std;
int nums[MAX]={0};
int main(){
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int dis= abs(x-i)+abs(y-j)+1;
			dis=min(dis,j-i);
			nums[dis]+=1;
		}
	}
	for(int i=1;i<=n-1;i++){
		printf("%d\n",nums[i]);
	}
	return 0;
}