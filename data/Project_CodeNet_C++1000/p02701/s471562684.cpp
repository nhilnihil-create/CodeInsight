#include <bits/stdc++.h>
using namespace std;

long N;
set<string> S;

int main(void) {

    cin >> N;

    for (long i = 0; i < N; i++) {
        string s; cin >> s;
        S.emplace(s);
    }

    cout << S.size() << endl;

    return 0;

}