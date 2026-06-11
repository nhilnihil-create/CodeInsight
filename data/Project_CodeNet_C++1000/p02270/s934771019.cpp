#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

int n, k;
vector<int> w;

bool isPack(int unit)
{
    int num = 1, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (unit < w[i])
            return false;
        if (sum + w[i] <= unit)
            sum += w[i];
        else {
            sum = w[i];
            ++num;
        }

        if (num > k)
            return false;
    }

    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int wi;

    cin >> n >> k;
    w.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> w[i];

    int l = 0, r = 100000 * 10000 + 1;
    while (l < r) {
        int mid = (l + r) * 0.5;
        if (isPack(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;

    return 0;
}