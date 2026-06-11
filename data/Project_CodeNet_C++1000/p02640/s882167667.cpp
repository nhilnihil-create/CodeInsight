#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int X,Y;
bool ans;

int main()
{
    int i,a;
    cin >> X >> Y;

    rep0(i, X+1)
    {
        a=i*2+(X-i)*4;
        if(a==Y) {ans=true; break;}
    }
    if(ans)
    cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}