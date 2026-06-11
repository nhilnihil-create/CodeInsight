#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int A = 5e2 + 2;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int freq[n] = {};
    for (int i = 1, x; i < n; i++)
        cin >> x, freq[x - 1]++;
    for (int i = 0; i < n; i++)
        cout << freq[i] << '\n';
    return 0;
}