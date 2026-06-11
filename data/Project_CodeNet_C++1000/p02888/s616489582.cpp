#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int a[2005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    ll sum = 0;
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int pos = lower_bound(a, a + n, a[i] + a[j]) - a;
            sum += pos - j - 1;
        }
    }
    cout << sum;
}

