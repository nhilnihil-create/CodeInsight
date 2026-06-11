#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using ull = unsigned long long;
using ll = long long;
using namespace std;

int main(void) {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> ans(N);

    for (int x = 1; x <= N; ++x) {
        for (int y = x+1; y <= N; ++y) {
            int d = y - x;
            int p = abs(X-x) + 1 + abs(Y-y);
            ans[min(d,p)]++;
        }
    }
    
    for (int i = 1; i < N; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}