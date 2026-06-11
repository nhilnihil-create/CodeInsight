// A.cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5e5 + 200;

int n, ans[MAX_N], deg[MAX_N];
char str[MAX_N];

int main()
{
    scanf("%s", str + 1), n = strlen(str + 1) + 1;
    for (int i = 1; i < n; i++)
        if (str[i] == '<')
            deg[i + 1]++;
        else
            deg[i]++;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u > 1 && str[u - 1] == '<')
            ans[u] = max(ans[u - 1] + 1, ans[u]);
        if (u < n && str[u] == '>')
            ans[u] = max(ans[u + 1] + 1, ans[u]);
        if (u > 1 && str[u - 1] == '>' && --deg[u - 1] == 0)
            q.push(u - 1);
        if (u < n && str[u] == '<' && --deg[u + 1] == 0)
            q.push(u + 1);
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
        answer += ans[i];
    printf("%lld\n", answer);
    return 0;
}