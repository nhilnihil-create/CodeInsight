#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int n, m;
    cin >> n >> m;

    int ans = n*(n-1)/2 + m*(m-1)/2;
    cout << ans << endl;

    return 0;
}