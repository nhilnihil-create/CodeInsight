#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll m,n;
    cin>>m>>n;
    int cnt = 0;
    for(int i=0;i<m;i++)
    {
        ll a,b,y;
        cin>>a>>b;
        y = a*a+b*b;
        if(y<=n*n)
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}