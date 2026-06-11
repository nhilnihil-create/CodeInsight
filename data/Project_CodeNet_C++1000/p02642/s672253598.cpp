#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll M=1000010;

int main() {
	ll N, ans=0;
	set<int> st;

	cin >> N;
	vector <ll> a(N);
	rep(i,N) cin >> a[i];
	vector <ll> con(M);

	for(int i:a){
		if (con[i] != 0){
			con[i]=2;
			continue;
		}
		for (int k = i; k < M; k += i)	con[k]++;
	}

	for (int i : a){
		if (con[i] == 1)ans++;
	}

	cout << ans << endl;

	return 0;
}