#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> a(n);
    rep(i, n) {
        cin >> a.at(i);
        if (((i + 1) * a.at(i)) % 2 == 1)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}