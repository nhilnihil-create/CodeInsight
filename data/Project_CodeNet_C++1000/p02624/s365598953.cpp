#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using V = vector<int>;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    long long int ans = 0;
    rep(i,n) {
        long long int j = n/(i+1);
        ans +=  j*(j+1)/2*(i+1);
    }
    cout << ans << endl;
    return 0;
}
