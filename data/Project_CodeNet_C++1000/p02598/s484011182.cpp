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
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
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

vector<ll> a ;

// index が条件を満たすかどうか
bool isOK(ll index, ll key) {
	ll count = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		ll u = 0;
		if(a.at(i) % index!=0)	u = a.at(i) / index;
		else	u = a.at(i) / index - 1;
		count += u;
	}
	if (count <= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
    ll ng = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = 1e9; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
	ll N, K;
	cin >> N >> K;
	a.resize(N);
	FOR(i, 0, N)	cin>>a.at(i);
	cout << binary_search(K) << endl;
	


	return 0;
}


