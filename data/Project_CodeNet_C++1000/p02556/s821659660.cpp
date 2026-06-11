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
    ll result = 0, smallest, cur;
    for (int p : {1, -1}) {
        for (int q : {1, -1}) {
            ll mn = 2e9, mx = -2e9;
            for (int i = 0; i < N; i ++){
                mn = min(mn, p*V[i].first + q*V[i].second);
                mx = max(mx, p*V[i].first + q*V[i].second);
            }
            result = max(mx - mn, result);
        }
    }
    cout << result << "\n";
}
