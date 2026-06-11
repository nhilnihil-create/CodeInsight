#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(void) {
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(int i=0; i<N; ++i)
        cin >> P[i];

    sort(P.begin(), P.end());
    int ret = 0;
    for(int i=0; i<K; ++i) {
        ret += P[i];
    }
    cout << ret << endl;
    return 0;
}