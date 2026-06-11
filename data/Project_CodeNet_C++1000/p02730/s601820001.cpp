#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<int(n); i++)
#define print(x) cout << (x) << endl

bool f(string s) {
    string revs = s;
    reverse(revs.begin(), revs.end());
    if (revs == s) return true;
    return false;
}

int main() {
    string s; cin >> s;
    int n = s.size();
    bool ans;
    string a = s.substr(0,(n-1)/2);
    string b = s.substr((n+2)/2);
    if (f(s) && f(a) && f(b)) ans = true;
    else ans = false;
    print(ans ? "Yes" : "No");

}