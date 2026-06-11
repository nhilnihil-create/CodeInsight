#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

int main(void){

    int n;
    cin >> n;
    vector<int> a(n);
    roop(i, n) cin >> a[i];

    int ans = 0;
    roop(i, n) ans ^= a[i];

    cout << (!ans ? "Yes" : "No") << endl;

    return 0;
}