#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

vector<string> s;

int main()
{
    ll n;
    ll ans;

    cin >> n;
    rep(i, n) {
        string s1;
        cin >> s1;
        s.push_back(s1);
    }

    sort(s.begin(), s.end()) ;

    ans = 1;
    rep(i, n-1) {
        if (s[i] != s[i + 1])
            ++ans;
    }

    std::cout << ans << endl;

    return(0);
}
