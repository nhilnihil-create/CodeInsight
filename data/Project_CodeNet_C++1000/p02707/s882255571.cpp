#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

int main()
{
    int n; cin >> n;
    int tmp;
    vector<int> ans(n+1);
    rep(i, n-1) {
        cin >> tmp;
        ans.at(tmp)++;
    }

    for(int i = 1; i < n+1; i++) {
        cout << ans.at(i) << endl;
    }
}