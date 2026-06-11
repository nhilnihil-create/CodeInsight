#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i = 0; i , (n); ++i)
using ll = long long;
using namespace std;
int sum(int n) {
    if (n == 0) {
        return 0;
    }

    int s = sum(n - 1);
    return s + n;
}
int main() {
    int N, K, sum=0;
    cin >> N >> K;
    vector<int>p(N);
        for (int i = 0;i < N;i++) {
            cin >> p.at(i);
        }
        sort(p.begin(), p.end());
        for (int i = 0;i < K;i++) {
            sum+=p.at(i);
        }
        cout << sum;
}