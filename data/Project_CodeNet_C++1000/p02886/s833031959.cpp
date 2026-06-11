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
	vector<int> D(N);
	for(int i = 0; i < N; i++){
		cin >> D[i];
	}
	ll ans = 0;
	for(int i = 0; i < N-1; i++){
		for(int j = i+1; j < N; j++){
			ans += D[i]*D[j];
		}
	}
	cout << ans << endl;

	return 0;
}
