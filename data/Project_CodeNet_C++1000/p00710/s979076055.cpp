#include <bits/stdc++.h>

using namespace std;

void cut(int *a, int p, int c)
{
    for(int i=0; i<c; i++)
    {
        int t = a[p+i];
        for(int j=p+i; j>i; j--)
        {
            a[j] = a[j-1];
        }
        a[i] = t;
    }
}

int main()
{
    int n, r;
    while(cin >> n >> r, n|r)
    {
        int a[n];
        for(int i=0; i<n; i++) a[i] = n - i;
        while(r--)
        {
            int p, c;
            cin >> p >> c;
            cut(a, p-1, c);
        }
        cout << a[0] << endl;
    }
}