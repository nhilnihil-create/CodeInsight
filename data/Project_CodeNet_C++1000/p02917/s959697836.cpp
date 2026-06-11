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
#include<numeric>
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

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> B(N - 1), A(N,1e6);
	FOR(i, 0, N - 1)
	{
		cin >> B.at(i);
	}

	FOR(i,0,N-1){
		if(B.at(i)<A.at(i))
			A.at(i) = B.at(i);
		if(B.at(i)<A.at(i+1))
			A.at(i+1) = B.at(i);
	}

	cout << accumulate(range(A), 0) << endl;

	return 0;
}

