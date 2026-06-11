#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



ll solve(vector<ll> a) {
    int n = a.size();
    vector<ll> acc(n+1, 0);
    for (int i=0; i<n; i++) {
	acc[i+1]=a[i];
	acc[i+1]+=acc[i];
    }

    ll res = acc[n];

    for (int i=0; i<n; i++) {
	ll left = acc[i+1];
	ll right = acc[n] - left;
	res = min(res, abs(left-right));
    }

    return res;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int n;
    cin>>n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }

    ll res = solve(a);
    reverse(a.begin(), a.end());
    res = min(res, solve(a));
    out(res);    
    return 0;
}
