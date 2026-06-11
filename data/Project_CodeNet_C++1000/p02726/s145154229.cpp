#include<bits/stdc++.h>
using namespace std;
int C[2005], x, y, n, i, j;
int main()
{
    cin >> n >> x >> y;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            C[min(abs(j-i),abs(x-i)+1+abs(y-j))]++;
        }
    }
    for(i=1;i<n;i++)
        cout << C[i] << endl;
    return 0;
}
