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
#define MP make_pair
using Graph = vector<vector<int>>;
const unsigned long long mod = 1e9 + 7;
const long long INF = 1LL<<60;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }

//https://algo-logic.info/calc-pow/
ll pow(ll x, long long n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x ;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	int K = pow(2, N);
	vector<ll> dp(K,INF);
	dp.at(0) = 0;
	FOR(i, 0, M)
	{
		ll a, b;
		cin >> a >> b;
		ll sum=0;
		while(b--){
			int c;
			cin >> c;
			sum += pow(2, c - 1);
		}
		chmin(dp[sum] ,a);
	}
	/*
	FOR(i, 0, K)
		cout << i << ":" << dp[i] << endl;
		*/

	for (int bit1 = 0; bit1 < K - 1; ++bit1)
	{
        for (int bit2 = bit1 + 1; bit2 < K; ++bit2) {
            ll nsum = bit1 | bit2;
			chmin(dp[nsum], dp[bit1] + dp[bit2]);
			//cout << bit1 << " " << bit2 << " " << nsum << endl;
		}
	}

	
	if(dp[K-1]==INF)
		cout << -1 << endl;
	else
		cout << dp[K - 1] << endl;
		
	/*
	FOR(i, 0, K)
		cout << i << ":" << dp[i] << endl;
		*/

	return 0;
}

