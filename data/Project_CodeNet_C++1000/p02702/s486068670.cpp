#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int mod = 2019;

int cnt[2020];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    vector<ll> b(n+1);
    int digit = 1;
    for(int i=n-1;i>=0;i--){
        int c = s[i] - '0';
        a[i] = c * digit;
        a[i] %= mod;
        digit *= 10;
        digit %= mod;
    }
    cnt[0] ++;
    for(int i=n-1;i>=0;i--){
        b[i] = b[i+1] + a[i];
        b[i] %= mod;
        cnt[b[i]]++;
    }
    ll ans = 0;
    for(int i=0;i<=2019;i++){
        ans += cnt[i]*(cnt[i]-1)/2;
    }
    cout << ans << endl;
}