// https://atcoder.jp/contests/abc158/tasks/abc158_c
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
#define lli long long int
#define numberofdigits(x) floor(log10(x)) + 1

int main()
{
    lli a,b,x,y,z,Z,flag=0;
    cin>>a>>b;
    x = (a*100)/8;
    y = b*10;
    lli a0 = min(x,y);
    lli b0 = max(x,y);
    for(lli i=1;i<=1000;i++)
    {
        z = (i*0.08);
        Z = (i*0.10);
        if(z==a && Z==b)
        {
            flag=1;
            cout<<i<<"\n";
            break;
        }
    }
    if(!flag)   cout<<"-1\n";
    return 0;
}