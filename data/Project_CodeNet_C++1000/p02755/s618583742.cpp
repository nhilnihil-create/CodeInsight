#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli a,b,i,y1,y2;
    cin>>a>>b;
    for(i=1;i<=1e4;i++)
    {
        y1=0.08*i;
        y2=0.1*i;
        if(y1==a && y2==b)
        {
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<-1<<"\n";
}