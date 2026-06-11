#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using vc   = vector<char>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vvc  = vector<vc>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;


int main() {
    string S, T; cin >> S >> T;
    int ans = S.length();

    for (int i = 0; i < S.length(); i++) {
        if (S.at(i) == T.at(i)) ans--;
    }    
    cout << ans << endl;
}