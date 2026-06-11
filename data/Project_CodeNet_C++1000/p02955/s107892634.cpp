#include<bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long x) {
    vector<long long> v;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            v.push_back(i);
            if(i * i != x) v.push_back(x / i);
        }
    }
    sort(v.begin(), v.end()); return v;
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];
    vector<long long> d = divisor(sum);
    long long ans = 1;
    for(auto&& x : d) {
        long long need;
        vector<long long> r(n);
        for(int i = 0; i < n; i++) r[i] = a[i] % x;
        sort(r.begin(), r.end());
        long long B = 0;
        for(int i = 0; i < n; i++) B += x - r[i];
        long long A = 0;
        need = 1e18;
        for(int i = 0; i < n; i++) {
            A += r[i];
            B -= x - r[i];
            need = min(need, max(A, B));
        }
        if(need <= k) ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}
