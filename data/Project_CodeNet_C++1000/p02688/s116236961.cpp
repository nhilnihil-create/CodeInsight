#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, K, d, a;
    cin >> N >> K;
    vector<int> count(N);
    for (int i = 0; i < K; i++) {
        cin >> d;
        for (int j = 0; j < d; j++) {
            cin >> a;
            count[a-1] = 1;
        }
    }
    cout << N - accumulate(count.begin(), count.end(), 0) << endl;
}