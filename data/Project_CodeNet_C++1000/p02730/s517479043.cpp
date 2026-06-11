#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

bool check(string s){
    string r = s;
    reverse(r.begin(), r.end());
    bool flag = true;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != r[i]) flag = false;
    }
    return flag;
}

int main(){
    string s;
    cin >> s;
    int n = s.length();
    if (check(s) && check(s.substr(0, (n-1)/2)) && check(s.substr((n+1) / 2, (n-1)/2))) cout << "Yes" << endl;
    else cout << "No" << endl;
}