#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
	ll N; cin >> N;
	ll mn = 2e18, mx = -2e18;
	vector < pair < ll, ll > > V(N);
	for (int i = 0; i < N; i ++){	
		ll X, Y; cin >> X >> Y; V[i].first = X; V[i].second = Y;
	}



	int res = 0, smallest, cur;
    for (int p : {1, -1}) {
        for (int q : {1, -1}) {
            smallest = p * V[0].first + q * V[0].second;
            for (int i = 1; i < N; ++i) {
                cur = p * V[i].first + q * V[i].second;
                res = max(res, cur - smallest);
                smallest = min(smallest, cur);
            }
        }
    }
    cout << res << "\n";

}