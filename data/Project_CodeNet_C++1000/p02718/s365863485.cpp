#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int n, count = 0;
    float m, sum = 0;
    vector<int> a(300);

    cin >> n >> m;
    rep(i, n){
        cin >> a.at(i);
        sum += a.at(i);
    }
    rep(i, n){
        if (a.at(i) >= sum / (4 * m))
            count++;
    }
    if (count >= m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
