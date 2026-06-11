#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> a(N);
    rep(i, N) {
        pair<int, int> p;
        cin >> p.second >> p.first;
        a.push_back(p);
    }
    sort(a.begin(), a.end());
    int time = 0;
    for (auto p : a) {
        time += p.second;
        if (time > p.first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}