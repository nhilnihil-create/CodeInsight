#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    
    int S = a[0];
    REP(i, N) S = S ^ a[i];
    if (S == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
