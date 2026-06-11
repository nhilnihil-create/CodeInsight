/******************************************
    > File Name: Aoj_0033.cpp
    > Author: universal42
    > Mail: universal42@163.com 
    > Created Time: 2019年05月03日 星期五 16时38分31秒
 ******************************************/

#include<bits/stdc++.h>
#define ll long long int
#define inf 0x3f3f3f3f
#define LOCALa
using namespace std;
const int maxn=1e5+5;
int n;
int arr[10],a[10],b[10];
int flag=0;
void dfs(int i,int j){
	if(flag){
		return;
	}
	if(i+j==10){
		for(int p=0;p<i-1;p++){
			if(a[p]>a[p+1]){
				return;
			}
		}
		for(int p=0;p<j-1;p++){
			if(b[p]>b[p+1]){
				return;
			}
		}
		flag=1;
		return;
	}
	a[i]=arr[i+j];
	dfs(i+1,j);
	b[j]=arr[i+j];
	dfs(i,j+1);
}
void solve(){
	scanf("%d",&n);
	while(n--){
		flag=0;
		for(int i=0;i<10;i++){
			scanf("%d",&arr[i]);
		}
		dfs(0,0);
		if(flag){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
}
int main(){
#ifdef LOCAL
    freopen("in.in","r",stdin);
#endif
    solve();
    return 0;
}

