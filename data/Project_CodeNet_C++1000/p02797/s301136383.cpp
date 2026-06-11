#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,sum;
    cin >> n >> m >> sum;
    for(int i = 0; i < m; i++)
        cout << sum  << ' ';
    if(sum != 1000000000)
        for(int i = m; i < n; i++)
            cout << sum+1 << ' ';
    else
        for(int i = m; i < n; i++)
            cout << sum-1 << ' ';
    return 0;
}
