#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int mid;
	if(m&1) mid=(m*2+1)/2;
	else mid=(m*2+1)/2+1;
	int cnt=1;
	for(int i=1;cnt<=m;cnt++,i++){
		if(cnt<=mid/2) printf("%d %d\n",i,mid-i+1);
		if(cnt==mid/2+1) i=mid+1;
		if(cnt>mid/2 ) printf("%d %d\n",i,mid+1+m*2+1-i); 
	}
}