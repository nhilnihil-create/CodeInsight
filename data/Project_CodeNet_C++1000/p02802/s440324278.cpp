// https://atcoder.jp/contests/abc151/tasks/abc151_c
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

vector<bool> vc[100005];

int main()
{
    lli n,m,p[100005],i,c=0,pen=0;
    char s[100005][4];
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>p[i]>>s[i];
        vc[p[i]].push_back((s[i][0]=='W' ? 0 : 1));
    }
    for(i=1;i<=n;i++)
    {
        lli flag=0,j;
        for(j=0;j<vc[i].size();j++)
        {
            if(vc[i][j]==1)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            c++;
            pen+=j;
        }
    }
    cout<<c<<" "<<pen<<"\n";
    return 0;
}