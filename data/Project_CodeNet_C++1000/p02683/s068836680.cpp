#include<stdio.h>
#include<iostream>
#include<algorithm>
#define debug freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
using namespace std;
const int MAXN=20;
typedef long long ll;
int a[MAXN][MAXN],temp[MAXN],ans[MAXN],mon[MAXN];
int n,m,x,sum=0,price=1e9;
int main()
{
	cin>>n>>m>>x;
	for(int i=0;i<n;i++){
		cin>>mon[i];
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				for(int k=0;k<m;k++){
					ans[k]+=a[j][k];
				}
				sum+=mon[j];
			}
		}
		int flag=0;
		for(int j=0;j<m;j++){
			if(ans[j]<x){
				flag=1;
				break;
			}
		}
		if(!flag) price=min(price,sum);
		sum=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				for(int k=0;k<m;k++){
					ans[k]-=a[j][k];
				}
			}
		}
	} 
	if(price==1e9) cout<<-1<<'\n';
	else cout<<price<<'\n';
	return 0;
}