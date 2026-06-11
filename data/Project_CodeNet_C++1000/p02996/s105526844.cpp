#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

int main() {
    int n;
    scanf("%d", &n);

    pair<ll, ll> t[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &t[i].second, &t[i].first);
    }

    sort(t, t + n);

    ll sum = 0;
    string ans = "Yes";
    for (int i = 0; i < n; i++) {
        sum += t[i].second;
        if (sum > t[i].first) {
            ans = "No";
            break;
        }
    }

    cout << ans << endl;
}