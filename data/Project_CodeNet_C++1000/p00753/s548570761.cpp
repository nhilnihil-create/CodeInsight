#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int qx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int qy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(void) {
	vector<ll> cnt(246913, 0);
	vector<bool> p(246913, true);
	FOR(i, 2, 246913) {
		if(p[i]) {
			cnt[i] = cnt[i - 1] + 1;
			for(ll j = 1; i * j <= 246912; ++j) {
				p[i * j] = false;
			}
		} else {
			cnt[i] = cnt[i - 1];
		}
	}
	while(true) {
		int n;
		cin>>n;
		if(n == 0)break;
		cout<<cnt[2 * n] - cnt[n]<<endl;
	}
}