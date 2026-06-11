#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
    ll n, k; cin >> n >> k;
    vector<int> a(n), sorted(n), cnt(n); for(int i = 0; i < n; i++)cin >> a[i];
    sorted = a;
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i < n; i++) {
        cnt[i] = sorted.end() - upper_bound(sorted.begin(), sorted.end(), a[i]);
    }
    //for(int i = 0; i < n; i++)cout << cnt[i] << endl;
    ll sum = 0;

    for(int i = 0; i < n; i++) {

        ll cur = ((k * (k - 1) / 2) % mod ) * cnt[i]; 
        cur %= mod;
        sum += cur; sum %= mod;
    }

    ll unit = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j])unit++;
        }
    }

    cout << (((unit * k) % mod) + sum) % mod << endl;

}