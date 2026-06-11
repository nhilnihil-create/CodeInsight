#include <bits/stdc++.h>
#define ll long long int
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
const ll maxn=1e18;
int main()
{
    int n;
    cin>>n;
    ll A[n];
    bool zero,over;
    zero=over=false;
    rep(i,n)
    {
        cin>>A[i];
        if(A[i]==0)
        {
            zero=true;
            break;
        }
    }
    if(zero)
    {
        cout<<0<<endl;
        return 0;
    }
    ll p=1;
    rep(i,n)
    {
        if(A[i]>maxn/p)
        {
            over=true;
            break;
        }
         p*=A[i];
    }
    if(over)
        cout<<-1<<endl;
    else
        cout<<p<<endl;
    return 0;
}
