#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin >> N;
    vector<pair<int, int>> ba;
    rep(i, 0, N)
    {
        int a, b;
        cin >> a >> b;
        ba.push_back(make_pair(b, a));
    }
    sort(ba.begin(), ba.end());
    ll time = 0;
    rep(i, 0, N)
    {
        time += ba[i].second;
        if (time > ba[i].first)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int main()
{
    func();
}