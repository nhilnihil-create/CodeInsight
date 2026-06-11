#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(30);
#define ll long long
#define pi 3.14159265359
using namespace std;

int main()
{
    IOS;
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)    cin>>a[i];
    sort(a,a+n);
    ll s=a[n-1];
    ll c= n-2;
    ll i = n-2;
    ll j=0;
    while(i>0){
        s+=a[c];
        j+=1;
        i--;
        if(j==2){
            c--;
            j=0;
        }
    }
    cout<<s;
    return 0;
}
