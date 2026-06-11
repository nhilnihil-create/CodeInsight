#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#define rep(i, n) for(i=0; i<n; i++)
#define pb push_back
#define ll long long
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, i;
    cin >> n;
    ll sum = 0, S=0;
    vector<ll> notch;
    for(i=0; i<n; i++){
        ll x;
        cin >> x;
        notch.pb(x);
        S += x;
    }
    ll mi = S+1;
    for(i=0; i<n; i++){
        sum += notch[i];
        mi = min(mi, abs(sum - (S-sum)));
    }
    cout << mi << endl;
    return 0;
}