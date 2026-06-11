#include<bits/stdc++.h>
using namespace std;
int n, m, i;
int main()
{
    cin >> n >> m;
    int x, y;
    for(i=1;i<=10000;i++)
    {
        x = i*0.08;
        y = i*0.10;
        if(x==n && y==m)
            break;
    }
    if(x==n && y==m)
        cout << i << endl;
    else
        cout << -1 << endl;
}
