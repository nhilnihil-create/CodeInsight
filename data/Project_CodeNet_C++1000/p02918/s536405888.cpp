//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n, k;
    cin >> n >> k;
    string S;
    cin >> S;
    string s_ = S;

    rep(i, S.size()-1) {
        if(S[i] == S[i+1]) {
            S = S.substr(0, i) + S.substr(i+1);
            --i;
        }
    }

    int num = n - S.size();

    cout << min(n-1, num+2*k) << endl;
}