#include <iostream>
#include <vector>
using namespace std;
#define ll long long
// 16:12 from

int main(){
//the biggest power of 2 that doesnot exceed n
	ll h;
	cin>>h;
	ll b=1;
	while(2*b<=h) b*=2;
	cout<<2*b-1;

}
// int h;
// 	cin>>h;
// 	vector<int> dp(h+1);
// 	dp[0]=0;
// 	dp[1]=1;
// 	for(int i=2;i<=h;i++){
// 		dp[i]=1+2*dp[i/2];
// 	}
// 	cout<<dp[h];
// 	return 0;

// #include <bit>
// This containe __builtin
// look at the video from 16:12