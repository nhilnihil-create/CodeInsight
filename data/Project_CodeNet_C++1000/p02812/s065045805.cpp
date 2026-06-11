/***
coded by adarsh
***/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef long double ld;
typedef vector<ll> vec; 
typedef vector<vector<ll>> vec2;
typedef pair<ll,ll> pair1;
typedef pair<string,ll> pair2;
typedef pair<ll,string> pair3;
typedef pair<string,string> pair4;
#define fl(i,a,b) for(i=a;i<b;i++)
#define rfl(i,a,b) for(i=b-1;i>=a;i--)
#define f first
#define s second

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n,i;cin>>n;
    string a;cin>>a;
    ll sum=0,c=0;
    for(i=0;i<n;i++)
    {
        if(a[i]=='A') c=1;
        else if(c==1)
        {
            if(a[i]=='B') c=2;
            else c=0;
        }
        else if(c==2)
        {
            if(a[i]=='C')
            {
                c=0;sum++;
            }
            else c=0;
        }
    }
    cout<<sum;
    return 0;
}
