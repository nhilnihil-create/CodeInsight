#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

#define MOD1097 1000000007

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mpair make_pair
#define pm(first, second) pb(mpair(first, second))
#define fpf first.first
#define fps first.second
#define spf second.first
#define sps second.second

#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define divcel(a, b) (((a) + ((b) - 1)) / (b))

int main(){

	int N;
	cin >> N;
	vector<pair<string, int>> V(N);
	string S;
	int t;
	for(int i = 0; i < N; i++){
		cin >> S >> t;
		V[i] = mpair(S, t);
	}
	string X;
	cin >> X;
	int ans = 0;
	bool flag = false;
	for(int i = 0; i < N; i++){
		if(flag)ans += V[i].second;
		if(V[i].first == X)flag = true;
	}
	cout << ans << endl;

	return 0;
}
