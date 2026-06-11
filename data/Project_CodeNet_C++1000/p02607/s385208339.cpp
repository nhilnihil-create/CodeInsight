#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);  cin.tie(0); 
    int n ,temp ,res=0;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> temp;
        if (i%2 && temp%2)
            res++;
    }
    cout << res;
    return 0;
}