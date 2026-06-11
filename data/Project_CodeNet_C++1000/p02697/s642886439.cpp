#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5;
const int mod=998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    if(n%2)
    {
        /*int i=1,j=n;
        while(m--)
        {
            cout<<i<<" "<<j<<'\n';
            i++;
            j--;
        }*/
        if(m==1)
        {
            cout<<1<<" "<<3<<'\n';
            return 0;
        }
        int i=1,j=n/2;
        while(m)
        {
            cout<<i<<" "<<j<<'\n';
            m--;
            i++;
            j--;
            if(i>=j)
                break;
        }
        i=n/2+1,j=n;
        while(m--)
        {
            cout<<i<<" "<<j<<'\n';
            i++;
            j--;
        }
    }
    else
    {
        int i=1,j=n/2;
        while(m)
        {
            cout<<i<<" "<<j<<'\n';
            m--;
            i++;
            j--;
            if(i>=j)
                break;
        }
        i=n/2+2,j=n;
        while(m--)
        {
            cout<<i<<" "<<j<<'\n';
            i++;
            j--;
        }
    }


}
