#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, A, B, C, D;
char sir[maxN];

bool canGo (int i, int j)
{
    if (i == j)
        return 1;
    if (i > j || sir[i] == '#')
        return 0;
    if (sir[i + 1] == '.')
        return canGo (i + 1, j);
    return canGo (i + 2, j);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d %d\n", &N, &A, &B, &C, &D);
scanf ("%s", sir + 1);
bool jumpOption = 0;
for (int i=B; i<=D; i++)
    if (sir[i] == '.' && sir[i - 1] == '.' && sir[i + 1] == '.')
        jumpOption = 1;
if (!canGo (A, C) || !canGo (B, D) || (D < C && !jumpOption))
    printf ("No\n");
else printf ("Yes\n");
return 0;
}
