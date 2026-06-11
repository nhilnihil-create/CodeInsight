#include <iostream>
using namespace std;

int total_allocation(int W[], int n, int k, int P) {
    int total = 0;
    int truck_P = 0;
    for (int i = 0; i < n; i++) {
        if (truck_P + W[i] <= P) {
            truck_P += W[i];
            total++;
        } else {
            k--;
            if (k == 0) return total;
            truck_P = 0;
            if (W[i] <= P) {
                truck_P += W[i];
                total++;
            }
        }
    }
    return total;
}

int main() {
    int n, k;
    cin >> n >> k;
    int W[n];
    for (int i = 0; i < n; i++) cin >> W[i];

    int P_max = 1e9;
    int left = 0, right = P_max, mid;
    int allocation;

    while (left < right) {
        mid = (left + right) / 2;
        allocation = total_allocation(W, n, k, mid);
        if (allocation >= n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << right << endl;
}
