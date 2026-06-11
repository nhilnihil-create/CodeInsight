#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;

    bool ok = true;
    for (int i = 0; i < s.size(); i += 2) {
        if(s[i] != 'h' || s[i+1] != 'i'){
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
