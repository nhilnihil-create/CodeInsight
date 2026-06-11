#include <bits/stdc++.h>
using namespace std;

string S;
int N;

void input() {
    cin >> N;
    cin >> S;
}

void solve() {
    input();
    string tmp = "No";
    int K = N / 2;
    if(N % 2 == 0 && S.substr(0, K) == S.substr(K, N)) tmp = "Yes";
    cout << tmp << endl;
    return;
}

int main() {
    solve();
    return 0;
}
