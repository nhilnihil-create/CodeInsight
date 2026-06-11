#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ull i=a; i<(b); i++)
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

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ull N, K, sum=0;	cin>>N>>K;
	FOR(i,K,N+2){
		sum+=i*(N-i+1)+1;
		sum%=mod;
	}

	cout<<sum<<endl;

    return 0;
}

