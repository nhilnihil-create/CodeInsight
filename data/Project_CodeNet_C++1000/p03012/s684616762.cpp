#include <iostream>
#include <numeric>
using namespace std;

int n;

int main() {
    cin >> n;
    int arr[n];
    for (int i=0; i<n;i++){
        cin >> arr[i];
    }
    int total;
    const size_t size = sizeof(arr) / sizeof(arr[0]);
    total = accumulate(arr, arr + size, 0);
    int left_sum = 0;
    int right_sum;
    int min_diff = 100000;
    for (int j=0; j<n; j++){
        left_sum += arr[j];
        right_sum = total - left_sum;
        min_diff = min(min_diff, abs(right_sum - left_sum));
    }
    cout << min_diff;

}