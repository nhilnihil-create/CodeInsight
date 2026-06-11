#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define vec vector<long long int>
#define fi first
#define se second
#define pb push_back
void sieve(vector<int> &x, int k)
{

    for (int i = 1; i <= k; i++)
    {
        x[i] = i;
    }
    int i = 2;
    while (i < k)
    {
        if (x[i] == i)
        {
            for (int j = i; j <= k; j = j + i)
            {
                if (x[j] == j)
                {
                    x[j] = i;
                }
            }
        }
        i++;
    }
}
set<int> prime(int k, vector<int> &x)
{
    set<int> ans;
    while (k != 1)
    {
        ans.insert(x[k]);
        k = k / x[k];
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<int> y;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        y.pb(t);
        m = max(m, t);
    }
    vector<int> x(m + 1);
    sieve(x, m);
    map<int, int> ans;
    int flag = 0;
    /*for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }*/

    for (int i = 0; i < n; i++)
    {
        set<int> p = prime(y[i], x);
        for (auto t : p)
        {
            ans[t]++;
            if (ans[t] > 1)
            {
                flag = 1;
            }
            if (ans[t] == n)
            {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 0)
    {
        cout << "pairwise coprime" << endl;
    }
    else if (flag == 1)
    {
        cout << "setwise coprime" << endl;
    }
    else
    {
        cout << "not coprime" << endl;
    }
}