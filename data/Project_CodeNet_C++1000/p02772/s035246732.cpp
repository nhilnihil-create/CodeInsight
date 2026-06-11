#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vl vector
using namespace std;
int main()
{
    ll t,i,n;
    ll a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2==0 && (n%3 && n%5))
        {
            cout<<"DENIED";
            return 0;
        }
    }
    cout<<"APPROVED";
    return 0;
}