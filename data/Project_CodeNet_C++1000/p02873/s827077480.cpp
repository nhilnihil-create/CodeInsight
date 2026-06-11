#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> a(n+1);
    for(int i = 0; i < n; i++) {
        if (s[i]=='<'){
            a[i+1] = max(a[i+1], a[i]+1);
        }
    }

    for(int i = n-1; i >=0; i--) {
        if (s[i]=='>'){
            a[i] = max(a[i], a[i+1]+1);
        }
    }
    ll sum=0;
    for(int i = 0; i < n+1; i++) {
        sum += a[i];
    }
    cout << sum << endl;

    return 0;
}