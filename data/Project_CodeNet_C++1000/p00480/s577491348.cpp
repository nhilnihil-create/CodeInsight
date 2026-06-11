#include<iostream>
#include<queue>
typedef long long int ll;
using namespace std;

int n;
int num[101];
int ans;

ll solve(){
	ll dp[21][n];

	for(int i=0;i<21;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=0;

	dp[ num[0] ][0]=1;


	for(int i=0;i<n;i++){
		for(int val=0;val<=20;val++){
			if(dp[val][i]>0){
				if(0<=val+num[i+1] && val+num[i+1]<=20)
					dp[ val+num[i+1] ][i+1]+=dp[val][i];
				if(0<=val-num[i+1] && val-num[i+1]<=20)
					dp[ val-num[i+1] ][i+1]+=dp[val][i];
			}
		}
	}
	return dp[ans][n-1];
}

int main(){

	cin>>n;
	n--;
	for(int i=0;i<n;i++)
		cin>>num[i];
	cin>>ans;

//end input

	cout<<solve()<<endl;
	return 0;
}