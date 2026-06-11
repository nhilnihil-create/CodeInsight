#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0;i < n;i++){
        cin >> a[i];
        a[i]--;
    }
    vector<long long> c(n,0);
    for (long long i = 0;i < n;i++){
        c[a[i]]++;
    }
    long long sum = 0;
    for (long long i = 0; i < n; i++){
        sum += c[i]*(c[i]-1)/2;
    }
    //cout << sum << endl;

    for (long long i = 0; i < n; i++){
        long long ans = sum;
        ans -= (c[a[i]])*(c[a[i]]-1)/2;
        ans += (c[a[i]]-1)*(c[a[i]]-2)/2;
        cout << ans << endl;
    }
}