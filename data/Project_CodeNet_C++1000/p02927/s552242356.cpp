#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, D, c=0, i, j, x, fl=0, sum;
    cin >> M >> D;
    for(i=2;i<10;i++)
    {
        for(j=2;j<10;j++)
        {
            sum = (i*10)+ j;
            if(sum>D)
            {
                fl = 1;
                break;
            }
            x = i*j;
            if(x<=M)
            {
                c++;
            }
            else if(x>M)
            {
                break;
            }
        }
        if(fl==1)
        {
            break;
        }
    }
    cout << c << endl;
    return 0;
}