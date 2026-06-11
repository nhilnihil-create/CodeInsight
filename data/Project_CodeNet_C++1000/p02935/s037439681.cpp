#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<double> A(N,0);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    double ans = 0;

    for(int i = 0; i < N; i++) {
        ans += A.at(i)/pow(2, i + 1);
    }
    cout << ans + A.at(A.size() - 1)/pow(2, A.size() ) << endl;

    return 0;
}