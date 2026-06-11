#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
struct node{
	int x,y;
}a[N];
int cx[N],cy[N],idx,idy;
vector<int>xx,yy;
map<long long,int>mp;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<k;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		cx[a[i].x]++,cy[a[i].y]++;
		if(cx[a[i].x]>cx[idx])idx=a[i].x;
		if(cy[a[i].y]>cy[idy])idy=a[i].y;
		mp[1LL*a[i].x*N+a[i].y]=1;
	}
	for(int i=1;i<=n;i++){
		if(cx[i]==cx[idx])xx.push_back(i);
	}
	for(int i=1;i<=m;i++){
		if(cy[i]==cy[idy])yy.push_back(i);
	}
	int f=1;
	for(int i=0;i<xx.size();i++){
		if(!f)break;
		for(int j=0;j<yy.size();j++){
			if(mp[1LL*xx[i]*N+yy[j]]==0){
				f=0;break;
			}
		}
	}
	printf("%d\n",cx[idx]+cy[idy]-f);
}