#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    deque<int> ans;
    while (N > 0) {
        ans.push_front(N % K);
        N /= K;
    }
    cout << ans.size() << endl;
}
