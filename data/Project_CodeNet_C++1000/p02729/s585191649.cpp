#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    int ans = n*(n-1)/2 + m*(m-1)/2;
    cout << ans << endl;
    return 0;
}
