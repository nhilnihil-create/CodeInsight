#include "bits/stdc++.h" 
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
    ll n;
    cin>>n;
    REP(i,1,n)
    {
        if(floor(i*1.08)==n)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<":(";
}