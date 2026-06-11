#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>
#include<utility>
#include<map>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define range(a) a.begin(), a.end()
#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
using Graph = vector<vector<int>>;
const unsigned long long mod = 1e9 + 7;
const long long INF = 1LL<<60;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }

int main(){
	int N, k, ans = 0;
	cin >> N;
	string S;
	cin >> S;
	S = '0' + S;
	k = N - 1;
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
	
	FOR(i, 1, N)	if (S.at(i) == S.at(N)) dp.at(N).at(i)++;

	for (int i = k; i > 0;--i){
		for (int j = i-1; j > 0;--j){
			if(S.at(i)==S.at(j)){
				dp.at(i).at(j) = min(abs(i - j), dp.at(i + 1).at(j + 1) + 1);
				ans = max(ans, dp.at(i).at(j));
			}else{
				dp.at(i).at(j) = 0;
			}
		}
		k--;
	}

	cout << ans << endl;
	/*
	FOR(i,2,N+1){
		FOR(j,1,i){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	

	return 0;
}
