#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            for(int k = j + 1; k < N; k++) {
                if(arr[i] != arr[j] && arr[j] != arr[k] && arr[i] != arr[k] && arr[i] + arr[j] > arr[k] && arr[j] + arr[k] > arr[i] && arr[i] + arr[k] > arr[j]) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
}