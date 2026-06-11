#include<iostream>    //I
#include<cstdio>
#include<map>
#include<string>
#include<list>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<set>
#include<functional>
using namespace std; 
typedef long long  ll;
const ll maxn=1e5+5;
struct node{
	int mon;
	int a[15];
}book[15];
int m,n,x;
int b[15];
int main(){
	cin>>n>>m>>x;
	for(int i=0;i<n;i++){
		cin>>book[i].mon;
		for(int j=0;j<m;j++){
			cin>>book[i].a[j];
		}
	}
	int ans=2e9;
	for(int i=0;i<(1<<n);i++){
		memset(b,0,sizeof(b));
		int sum=0;
		for(int j=0;j<n;j++){
			if(i>>j&1){
				sum+=book[j].mon;
				for(int k=0;k<m;k++) b[k]+=book[j].a[k];
			}
		}
		bool flag=1;
		for(int j=0;j<m;j++) if(b[j]<x) flag=0;
		if(flag) ans=min(ans,sum);
	}
	if(ans==2e9) cout<<"-1\n";
	else cout<<ans<<endl;
	return 0;
} 