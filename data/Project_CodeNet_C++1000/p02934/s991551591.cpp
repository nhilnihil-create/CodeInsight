#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define ll long long
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define vali 1000000000000000000
using namespace std;
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
// Returns LCM of array elements 
ll findlcm(ll arr[], ll n) 
{ 
    // Initialize result 
    ll ans = arr[0]; 
  
    // ans contains LCM of arr[0], ..arr[i] 
    // after i'th iteration, 
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 
int main()
{
    ll n;
    l sum=0.0;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    ll lcm=findlcm(a,n);
    for(int i=0;i<n;i++)
    {
        sum+=(l)(lcm/a[i]);
    }
    cout<<fixed<<setprecision(7)<<(l)(lcm/sum)<<endl;
}