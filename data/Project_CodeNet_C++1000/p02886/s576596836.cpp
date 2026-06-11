#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
int main()
{
ll n,s=0; cin>>n;
ll a[n];
for(ll i=0;i<n;i++)
{
    cin>>a[i];
}
for(ll i=0;i<n;i++)
{
    for(ll j=i+1;j<n;j++){
    s+=a[i]*a[j];
}
}
cout<<s<<endl;
}
