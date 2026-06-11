#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,d,d1,d0,c=0,i,j,l;
    cin >> m >> d;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=d;j++)
        {
        d1 = j%10;
        d0 = j/10;
        l = d1*d0;
        if(d1>=2&&d0>=2&&l==i)
            {c++;

            }
        }
    }
    cout << c << endl;
}
