#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n){
		if(!n)
			break;
		int DP[31];
		DP[0] = 1;
		DP[1] = 1;
		DP[2] = 2;
		for(int i=3;i<=n;i++){
			DP[i] = DP[i-1]+DP[i-2]+DP[i-3];
		}
		int ans = DP[n]/10;
		if(DP[n]%10!=0)
			ans++;
		int answer = ans/365;
		if(ans%365!=0)
			answer++;
		cout << answer << endl;
	}
	return 0;
}