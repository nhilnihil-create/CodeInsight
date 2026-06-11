#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<double> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    double ans;
    
    sort(v.begin(), v.end(), greater<>());
    for (int i = 1; i < N; i++)
    {
        v[N-i-1] = (v[N-i] + v[N-i-1]) / 2;
        v.pop_back();
        sort(v.begin(), v.end(), greater<>());
    }
    
    ans = v[0];
    cout << std::fixed << std::setprecision(15) << ans << endl;
}

int main() {
    solve();
    return 0;
}