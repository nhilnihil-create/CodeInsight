#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    if(a%2==b%2)
    {
        cout<<(b-a)/2;
        return 0;
    }
    else
    {
        if(b<=a)
        {
            swap(a,b);
        }
        cout<<min(a+(b-1-a)/2,(n+1-b)+((n+1-a)-1-(n+1-b))/2);
        return 0;
    }
    return 0;
}
