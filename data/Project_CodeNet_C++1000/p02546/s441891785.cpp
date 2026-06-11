#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;

const int MOD = 1e9+7;
const ll INF = 1e16;

int main() {
    FASTIO

    string s;
    cin >> s;
    
    if(s[s.size()-1] == 's') cout << s+"es" << "\n";
    else cout << s+"s" << "\n";
    
    return 0;
}