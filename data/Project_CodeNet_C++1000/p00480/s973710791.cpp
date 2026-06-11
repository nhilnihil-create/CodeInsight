#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,a,t1,t2;
	long long dp[101][21]={0};
	cin>>n>>a;
	dp[0][a]=1;
	for(int i=1;i<n-1;i++){
		cin>>a;
		for(int j=0;j<=20;j++){
			if(dp[i-1][j]!=0){
				t1=a+j;
				t2=j-a;
				if(t1>=0&&t1<=20){
					dp[i][t1]+=dp[i-1][j];
				}
				if(t2>=0&&t2<=20){
					dp[i][t2]+=dp[i-1][j];
				}
			}
		}
	}
	cin>>a;
	printf("%lld\n",dp[n-2][a]);
}