#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int X, N;
bool p[101];

int main()
{
    cin >> X>>N;

    int i,j;
    rep0(i,N)
    {
        cin>>j;
       if(!p[j]) p[j]=true;
    }

    int s=0,l=0;
    rep0(i,N+1){
        if(!p[X-s]){cout << X-s << endl;break;}
        if(!p[X+l]){cout << X+l << endl;break;}
        s++; l++;
    }

    return 0;
}