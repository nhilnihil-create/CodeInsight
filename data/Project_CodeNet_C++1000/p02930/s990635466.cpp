#include <bits/stdc++.h>

using namespace std;

const int N = 550;

int a[N][N];

void Solve(vector <int> v, int Cur)
{
    if(v.size() < 2)    return ;

    int n = v.size();
    int m = n / 2;

    for(int i = 0; i < m; i++)
        for(int j = m; j < n; j++)
            a[v[i]][v[j]] = a[v[j]][v[i]] = Cur;

    vector <int> v1, v2;

    for(int i = 0; i < m; i++)  v1.push_back(v[i]);
    for(int j = m; j < n; j++)  v2.push_back(v[j]);

    Solve( v1, Cur + 1);
    Solve( v2, Cur + 1);
}

int main()
{
    int n;  cin >> n;

    vector <int> v;

    for(int i = 1; i <= n; i++) v.push_back(i);

    Solve( v, 1);

    for(int i = 1; i < n; i++, puts(""))
        for(int j = i + 1; j <= n; j++)
            printf("%d ", a[i][j]);
}
