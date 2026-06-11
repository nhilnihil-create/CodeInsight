#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;
    int sum = 0;
    for (int i = 0; i < S.size()/2; i++) {
        if (S[i] != S[S.size() - i - 1]) sum++;
    }
    cout << sum << endl;
    return 0;
}
