#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll t,n,f,i,tog;
    cin>>n;
    string s,a,b;
    cin>>s;
    if(n%2==1)
        cout<<"No";
    else
    {
        a=s.substr(0,n/2);
        b=s.substr(n/2,n/2);
        if(a==b)
            cout<<"Yes";
        else
            cout<<"No";
    }
}
