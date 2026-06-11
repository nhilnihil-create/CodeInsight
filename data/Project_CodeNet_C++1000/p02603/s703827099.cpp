#include <bits/stdc++.h>
using namespace std;
long long dp[100][1000];
long long arr[200];
const int MAX = 700;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0;i <= 81;i++){
		for(int j = 1;j <= 850;j++){
			dp[i][j] = -1;
		}
	}
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> arr[i];
	long long money = 1000;
	for(int i = 1;i <= n - 1;i++){
		long long st = 0;
		if(arr[i] < arr[i + 1])st = money / arr[i];
		money += (arr[i + 1] - arr[i]) * st;
	}
	cout << money;
	return 0;
}