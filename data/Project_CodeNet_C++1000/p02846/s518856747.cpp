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
	ll a1, a2, b1, b2, t1, t2;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	if(t1*(a1-b1)==t2*(b2-a2)){
		cout << "infinity" << endl;
		return 0;
	}
	if(a1<b1){
		swap(a1, b1);
		swap(a2, b2);
	}

	if(a2>b2){
		cout << 0 << endl;
		return 0;
	}
	if(t1*(a1-b1)>t2*(b2-a2)){
		cout << 0 << endl;
		return 0;
	}

	ll L=t1*(a1-b1), l=(t2*(b2-a2)+t1*(b1-a1));
	ll K = L / l;
	if(K*l==L)
		cout << K * 2 << endl;
	else
		cout << K * 2 + 1 << endl;

	return 0;
}

