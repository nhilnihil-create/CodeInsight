#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2e5+1;
ll a[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n, total = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total ^= a[i];
    }
    for(int i = 0; i < n; i++) {
        cout << (total^a[i]) << ' ';
    }
    return 0;
}
