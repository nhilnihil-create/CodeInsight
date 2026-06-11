#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

void InsertionSort(vector<int> &a, int n, int g, int &cnt)
{
    for (int i = g; i < n; ++i) {
        int v = a[i], j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j + g] = a[j];
            j -= g;
            ++cnt;
        }
        a[j + g] = v;
    }
}

void ShellSort(vector<int> a, int n)
{
    if (n == 1) {
        cout << "1\n1\n0\n" << a[0] << '\n';
        return ;
    }

    int cnt = 0;
    vector<int> g;

    for (int h = 1; h < n; ) {
        g.emplace_back(h);
        h = 3 * h + 1;
    }

    int m = g.size();

    cout << m << "\n";
    for (int i = m - 1; i >= 0; --i) {
        cout << g[i] << (i == 0 ? '\n' : ' ');
        InsertionSort(a, n, g[i], cnt);
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << '\n';
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ShellSort(a, n);

    return 0;
}