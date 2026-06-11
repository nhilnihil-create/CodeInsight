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

int factorial(int n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll i,n,j;cin>>n;
    int a[n],b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    fl(i,0,n) cin>>b[i];
    ll c=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i]>a[j])
            c++;
        }
        a[i]=c;c=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(b[i]>b[j])
            c++;
        }
        b[i]=c;c=0;
    }
    ll sum1=0,sum2=0;
    for(i=0;i<n-1;i++)
    {
        sum1+=a[i]*factorial(n-i-1);
        sum2+=b[i]*factorial(n-i-1);
    }
    cout<<abs(sum1-sum2);
    return 0;
}
