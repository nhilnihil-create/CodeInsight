#include<iostream>
using namespace std;

int main() {
    int n, k;
    int h[100010];

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> h[i];

    int count = 0;
    for(int i = 0; i < n; i++) {
        if (h[i] >= k) count++;
    }

    cout << count << endl;
}