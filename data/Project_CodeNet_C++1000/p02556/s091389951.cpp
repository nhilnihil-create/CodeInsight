#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr1(N), arr2(N);
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        arr1[i] = x + y;
        arr2[i] = x - y;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    cout << max(arr1[N - 1] - arr1[0], arr2[N - 1] - arr2[0]) << endl;
}