#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int cnt = S.size();
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == S[i+1]) cnt--;
    }
    cout << cnt << endl;
}