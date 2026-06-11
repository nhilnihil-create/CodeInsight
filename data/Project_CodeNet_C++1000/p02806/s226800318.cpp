#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<pair<string, int>> M(N);
    string S;
    for (int i = 0; i < N; i++) cin >> M[i].first >> M[i].second;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (M[i].first != S) ans += M[i].second;
        else ans = 0;
    }
    printf("%d\n", ans);
}
