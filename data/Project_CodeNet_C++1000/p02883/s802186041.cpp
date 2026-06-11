#include<bits/stdc++.h>

using namespace std;

int n;
long long k;
int main()
{
    cin >> n >> k;
    vector<int> a(n), b(n);

    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    long long l = 0;
    long long r = 1e12;
    while(l < r){
        long long sum = 0;
        long long m = (l + r) / 2;
        for(int i = 0; i < n; i ++){
            /// a[i] * b[i] <= m

            long long x = m / b[i];
            if(a[i] > x){
                sum += a[i] - x;
            }
        }
        if(sum <= k) r = m;
        else l = m + 1;
    }
    cout << l << "\n";
}
