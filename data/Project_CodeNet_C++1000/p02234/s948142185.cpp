#include <iostream>
#define INF 1000000
using namespace std;

int n;
int matrix[110][2];
int _dp[110][110];

int dp(int begin,int end){
	if(_dp[begin][end]) return _dp[begin][end];
	if(begin + 1 == end){
		_dp[begin][end] == 0;
		return 0;
	}
	if(begin + 2 == end){
		int temp = matrix[begin][0] * matrix[begin][1] * matrix[end-1][1];
		_dp[begin][end] = temp;
		return temp;
	}
	int min = INF;
	for(int i = begin+1; i<end; i++){
		int temp = dp(begin, i) + dp(i, end)
			+ matrix[begin][0] * matrix[i][0] * matrix[end-1][1];
		if(temp < min) min = temp;
	}
	_dp[begin][end] = min;
	return min;
}

int main(void){
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) cin >> matrix[i][0] >> matrix[i][1];
	
	cout << dp(0,n) << endl;
	
	return 0;
}
