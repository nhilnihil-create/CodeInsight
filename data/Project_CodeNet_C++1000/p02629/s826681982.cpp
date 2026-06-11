#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    ll n;
    cin >> n;
    string ans;

    while(n) {
        int x;
        n--;
        x = n % 26;
        char c = (char('a'+ x));
        ans += c;
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}