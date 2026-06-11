#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t ;
    t = 1;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        for(int j=1;j<100000001;j++)
        {
            ll x = j*n;
            if(x%360==0)
            {
                cout<<j;
                break;
            }
        }
    }
    return 0;
}