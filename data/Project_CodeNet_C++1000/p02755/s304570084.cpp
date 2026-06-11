#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int a, b ;
    cin >> a >> b ;

    for (int i = 0; i < 1250; i++)
    {
        if(a==(int)((i+1)*0.08)&&b==(int)((i+1)*0.1))
        {
            cout << i+1 << endl ;
            return 0 ;
        }
    }
    cout << -1 << endl ;
    
}