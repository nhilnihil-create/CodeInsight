#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//FILE *fi = freopen("1.txt", "r", stdin);
//FILE *fo = freopen("1", "w", stdout);
//FILE *fi = freopen("P.inp", "r", stdin);
//FILE *fo = freopen("P.out", "w", stdout);
bool used[1000001];
void bfs(int x)
{
    queue<int> q;
    if (used[x])
        return;
    q.push(x);
    used[x] = true;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        used[u] = true;
        u += x;
        if (u <= 1e6 && !used[u])
            q.push(u);
    }
    return;
}
int a[1000001];
int Min[1000001];
int main()
{
    //------------------------------
    // Faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //------------------------------
    int N = 1e6;
    for (int i = 1; i <= N; i++)
        Min[i] = i;
    for (int i = 2; i <= sqrt(N); i++)
    {
        for (int j = i; j <= N; j += i)
        {
            Min[j] = min(Min[j], i);
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bool ok = false;
    int G = 0;
    for (int i = n; i >= 1; i--)
    {
        G = __gcd(G, a[i]);
        if (a[i] == 1)
            continue;
        vector<int> U;
        while (a[i] > 1)
        {
            int x = Min[a[i]];
            if (used[x])
            {
                ok = true;
            }
            U.push_back(x);
            a[i] /= x;
        }
        for (auto x : U)
            bfs(x);
    }
    if (ok == false)
    {
        cout << "pairwise coprime";
    }
    else if (ok == true && G == 1)
    {
        cout << "setwise coprime";
    }
    else
    {
        cout << "not coprime";
    }
    return 0;
}