#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() { 
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) {
        string S;
        cin >> S;
        sort(S.begin(), S.end());
        s[i] = S;
    }
    sort(s.begin(), s.end());
    ll count;
    int j;
    ll ans = 0;
    rep(i, n) {
        count = 1;
        j = i + 1;
        while(s[i] == s[j]) {
            count++;
            j++;
        }
        ans += count * (count - 1) / 2;
        i = j - 1;
    }
    cout << ans << endl;
}