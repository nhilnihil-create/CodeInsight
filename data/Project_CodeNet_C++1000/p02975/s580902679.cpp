#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    int a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    sort(a, a + N);
    vector<pair<int, int>> v;
    int tmp = 1;
    for(int i = 1; i < N; i++) {
        if(a[i - 1] != a[i]) {
            v.push_back({a[i - 1], tmp});
            tmp = 1;
        } else
            tmp++;
    }
    v.push_back({a[N - 1], tmp});

    if(v.size() > 3)
        cout << "No";
    else if(v.size() == 3 && N % 3 == 0) {
        if((v[0].first ^ v[1].first) == v[2].first && v[0].second == N / 3 && v[1].second == N / 3 && v[2].second == N / 3) {
            cout << "Yes";
        } else
            cout << "No";
    } else if(v.size() == 2 && N % 3 == 0 && v[0].second == N / 3 && v[0].first == 0)
        cout << "Yes";
    else if(v.size() == 1 && v[0].first == 0)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
