#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n; cin >> n;
    vector<double> vec(n);
    rep(i, n) cin >> vec.at(i);
    sort(vec.begin(), vec.end());
    double x = (vec.at(0) + vec.at(1)) / 2;
    for(int i = 1; i < n-1;i++) {
        x = (x + vec.at(i+1))/2;
    }
    cout << x << endl;
    return 0;
}
