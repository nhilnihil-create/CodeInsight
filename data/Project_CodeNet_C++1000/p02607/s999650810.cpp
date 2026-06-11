#define ll long long int

#include <bits/stdc++.h>

using namespace std;
const int N = 200;
int arr[N];

int main() {

    int n;
    cin >> n;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] % 2 && (i + 1) % 2)cnt++;
    }
    cout << cnt << endl;

    return 0;
}