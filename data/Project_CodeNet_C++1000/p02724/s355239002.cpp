#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long x;
    cin >> x;
    int c500 = x / 500; 
    int r500 = x % 500; 
    int c5 = r500 / 5; 
    cout << c500 * 1000 + c5 * 5 << "\n";
    return 0;
}
