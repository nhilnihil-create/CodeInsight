#include <iostream>

using namespace std;
int x,n,v[10001],y;
int main()
{
    cin >> x >> n;
    if(n == 0) cout << x;
    else
    {
        for(int i = 1; i <= n; ++i)
        {
            cin >> y;
            v[y] = 1;
        }
        for(int i = 0; i <= n; ++i)
        {
            if(x-i == 0)
            {
                cout << 0;
                break;
            }
            if(!v[x-i])
            {
                cout << x-i;
                break;
            }
            if(!v[x+i])
            {
                cout << x+i;
                break;
            }
        }
    }
    return 0;
}
