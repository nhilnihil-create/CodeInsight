#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    int ans = (n%2==0)?(n/2):(n/2+1);
    cout << ans << endl;
    return 0;
}
