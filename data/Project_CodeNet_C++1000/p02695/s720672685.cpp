#include <iostream>
#include <vector>
using namespace std;

void search(vector<vector<int>> &perms, vector<int> &perm, int n, int k, int r, int s)
{
    if (r == 0)
    {
        vector<int> tmp;
        for (int i:perm) tmp.push_back(i);
        perms.push_back(tmp);
        return;
    }
    else
    {
        for (int i = s; i < n - r + 2; i++) 
        {
            perm[k - r] = i;
            search(perms, perm, n, k, r-1, i+1);
        }
    }
}

int main(void)
{
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(q), b(q), c(q), d(q);
    for (int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<vector<int>> perms;
    vector<int> perm(n);
    search(perms, perm, n + m - 2, n, n, 0);
    int ans = 0;
    int tmp, diff;
    for (auto p:perms)
    {
        tmp = 0;
        for (int i = 0; i < q; i++)
        {
            diff = (p[b[i]-1] - (b[i] - 1)) - (p[a[i]-1] - (a[i] - 1));
            if (diff == c[i]) tmp += d[i];
        }
        ans = max(tmp, ans);
    }
    cout << ans << endl;
}