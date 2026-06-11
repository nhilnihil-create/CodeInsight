#include<bits/stdc++.h>
using namespace std;
int dp[10][10];

int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		vector<int>arr;
		int num = i;
		while(num){
			arr.push_back(num%10);
			num/=10;
		}
		dp[*arr.begin()][*arr.rbegin()]++;
	}
	long long ret = 0;
	for(int i=1; i<=n; i++){
		vector<int>arr;
		int num = i;
		while(num){
			arr.push_back(num%10);
			num/=10;
		}
		ret+=dp[*arr.rbegin()][*arr.begin()];
	}
	cout<<ret;
}