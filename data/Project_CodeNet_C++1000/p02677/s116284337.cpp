#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod  = 1e9 + 7;
const ll INF = 1e14;

const double pi = 3.141592653589793238;

void solve(){

    double a, b, h, m; cin >> a >> b >> h >> m;

    double theta = (2 * pi * 11.0 / 12.0) * (h + m / 60.0);

    double res = powf128(a*a + b*b - 2*a*b*cosf128(theta), 0.5);

    cout << res;

}


//2pi(1 - 1/12)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    cout << setprecision(10);
    //int test; cin >> test;
    //for(int t = 1; t <= test; ++t){
        solve();    
    //}

	return 0;
}

