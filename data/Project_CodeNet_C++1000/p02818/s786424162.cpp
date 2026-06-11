#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ll a,b,k;cin >> a >>b>>k;
    if (a<=k)
    {
        k-=a;
        a=0;
        if (b<=k)
        {
            k-=b;
            b=0;
        }
        else
        {
            b-=k;
        }
        
    }
    else
    {
        a-=k;
    }
    cout << a<<" " << b << endl;
    return 0;
    
}