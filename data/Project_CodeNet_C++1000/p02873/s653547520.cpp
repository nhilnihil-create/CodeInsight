#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S; cin >> S;
    vector<int> N;
    rep(i,S.size()) {
        int cnt = 1;
        int j = i + 1;
        while (j < S.size() && S[i] == S[j]) j++, cnt++;
        N.push_back(cnt);
        i = j - 1;
    }
    bool less = (S[0] == '<');
    int i = 0;
    while (i < N.size()-1) {
        if (less) {
            if (N[i] < N[i+1]) N[i]--;
            else N[i+1]--;
        }
        less = !less;
        i++;
    }
    ll sum = 0;
    rep(i,N.size()) sum += ((ll)N[i] * (N[i]+1))/2;
    cout << sum << endl;
}
