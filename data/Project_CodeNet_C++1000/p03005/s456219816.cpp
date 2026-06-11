#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << "0\n";
    }
    else {
        cout << n - k << "\n";
    }

    return 0;
}