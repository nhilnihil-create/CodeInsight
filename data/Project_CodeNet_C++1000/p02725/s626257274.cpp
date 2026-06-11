#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>


void test_case()
{
    ll k,n;
    cin>>k>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll maxgap=0;
    for(int i=0;i<n-1;i++)
        maxgap=max(maxgap, a[i+1]-a[i]);
    maxgap=max(maxgap, a[0]+k-a[n-1]);
    cout<<k-maxgap;
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
