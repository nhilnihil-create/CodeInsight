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

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, count = 0;
	cin >> N;
	Graph G(N, vector<int>(N - 1, 0));
	FOR(i,0,N){
		FOR(j,0,N-1){
			int A;
			cin >> A;
			--A;
			G.at(i).at(j) = A;
		}
	}
	while (1)
	{
		vector<int> check;
		FOR(i,0,N){
			if(G.at(i).size()==0)
				continue;
			if(G.at(G.at(i).at(0)).size()==0)
				continue;
			if (G.at(G.at(i).at(0)).at(0) == i)
			{
				check.push_back(i);
				continue;
			}
		}
		if (check.size() == 0)
			{
				cout << -1 << endl;
				return 0;
		}
		FOR(i,0,check.size()){
			G.at(check.at(i)).erase(G.at(check.at(i)).begin());
		}
		bool r = true;
		FOR(i, 0, N)
		{
			if(G.at(i).size()!=0){
				r = false;
				break;
			}
		}
		count++;
		if(r){
			cout << count << endl;
			return 0;
		}
	}

	return 0;
}

