#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e7+5;
int ans[maxn]={0};
int main(){
	long long n;
	//cin>>n;
	scanf("%lld",&n);
	long long cnt=0;
	for(int i=1;i<n;i++){
		if(ans[i]==0&&ans[n-i]==0&&i!=n-i){
			ans[i]=ans[n-i]=1;
			cnt++;
		}
		//printf("%lld",cnt);
	}
	printf("%lld",cnt);
	
	
	return 0;
}