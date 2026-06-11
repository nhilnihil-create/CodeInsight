#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e5 + 5;

long long n;
pair<long long, long long> r[maxn];

bool comp(pair<long long, long long> p1, pair<long long, long long> p2) {
	return p1.second < p2.second;
}

int main() {
    cin >> n;
    long long x, l;
    for (long long i=0; i<n; i++) {
        cin >> x >> l;
        r[i].first = x - l;
        r[i].second = x + l;
    }
    sort(r, r + n, comp);
    long long ans = 1, r1 = r[0].second;
    for (long long i=1; i<n; i++) {
    	long long l1 = r[i].first, r2 = r[i].second;
    	if (l1 >= r1) {
    		ans++;
    		r1 = r2;
    	}
    }
    cout << ans << "\n";
}