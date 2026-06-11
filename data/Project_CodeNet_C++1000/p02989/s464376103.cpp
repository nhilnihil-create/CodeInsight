#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    }
    int ans = 0;
    sort(A.begin(),A.end());
    ans = A.at(N/2) - A.at(N/2 - 1);

    cout << ans << endl;



    return 0;
}