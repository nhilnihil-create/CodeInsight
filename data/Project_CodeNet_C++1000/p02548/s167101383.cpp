#include<bits/stdc++.h>
using namespace std;

#define mod 1e9+7
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
#define ll long long
#define lli long long int
#define el '\n'
#define mem(a,b) memset(a, b, sizeof(a) )

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
/**/
int main()
{
    optimize();
    ll t,n,x,y,k,z,m,a,b;
    cin>>n;

    ll cnt=0;
    for(ll i=1; i<n; i++)
    {
        for(ll j=1; i*j<n; j++)
        {
            cnt++;
        }
    }
    cout<<cnt<<el;

    return 0;
}
/**/

