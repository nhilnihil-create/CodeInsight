#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int ans = 0;
    vector<int> arr(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        if ((i & 1) && (arr[i] & 1)) {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}