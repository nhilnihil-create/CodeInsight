#include <bits/stdc++.h>
#include <stdio.h>
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

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll sum=0,N,d;	cin>>N;
	vector<int> data(N);
	FOR(i,0,N){
		cin>>d;
		data.at(i)=d;
	}
	FOR(i,0,N-1){
		FOR(j,i+1,N){
			sum+=data.at(i)*data.at(j);
		}
	}

	cout<<sum<<endl;

    return 0;
}

