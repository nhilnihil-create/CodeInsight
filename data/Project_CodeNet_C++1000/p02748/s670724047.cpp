#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int A = 0;
    cin >> A;
    int B = 0;
    cin >> B;
    int M = 0;
    cin >> M;
    int ans = 100000000;
    vector<int> a(A,0);
    for(int i = 0; i < A; i++) {
        cin >> a.at(i);
    }
    vector<int> b(B,0);
    for(int i = 0; i < B; i++) {
        cin >> b.at(i);
    }

    int x, y, c;
    for(int i = 0; i < M; i++) {
        cin >> x >> y >> c;
        ans = min(ans,a.at(x - 1) + b.at(y - 1) - c);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    cout << min(ans,a.at(0) + b.at(0)) << endl;

    return 0;
}