#include <bits/stdc++.h>

using namespace std;

int n, top, a[300100], f[300100], pre[300100];

void Input()
{
    ios_base::sync_with_stdio(0);       cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        int x;      cin >> x;
        a[x]++;
    }

    for (int i=1; i<=n; i++)
        if (a[i] > 0) f[++top] = a[i];

    sort(f + 1, f + top + 1);
    for (int i=1; i<=top; i++)
        pre[i] = pre[i-1] + f[i];
}

bool check(int t, int k)
{
    int l = -1, r = top + 1;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;

        if (f[mid] < t) l = mid;
            else r = mid;
    }

    int sum = pre[l] + (top - l)*t;
    if (sum/t < k) return false;
    return true;
}

void Process()
{
    for (int i=1; i<=n; i++)
    {
        int l = 0, r = 1000000;

        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (check(mid, i)) l = mid;
                else r = mid;
        }

        cout << l << endl;
    }
}

int main()
{
    Input();
    Process();
    return 0;
}
