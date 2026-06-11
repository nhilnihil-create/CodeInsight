#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m, p;
    string s;
    scanf("%d", &n);
    scanf("%d", &m);
    int prob[n] = {};
    bool bprob[n] = {};
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        cin >> s;
        if (!bprob[p - 1])
        {
            if (s == "WA")
                prob[p - 1]++;
            else if (s == "AC")
                bprob[p - 1] = true;
        }
    }
    int solved = 0, penalty = 0;
    for (int i = 0; i < n; i++)
    {
        if (bprob[i])
        {
            penalty += prob[i];
            solved++;
        }
    }
    printf("%d %d\n", solved, penalty);
}