#include<bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    map<string, bool> mapa;
    for (int i = 0; i < N; ++i) {
        string kind;
        cin >> kind;
        mapa[kind] = true;
    }
    cout << mapa.size() << '\n';
}
