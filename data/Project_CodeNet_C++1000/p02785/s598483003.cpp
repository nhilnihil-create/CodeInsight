#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool comp1(pair<int,int> &a,pair<int,int> &b)
{
    return a.second>b.second;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll sum=0;
    for(int i=0;i<n-k;i++){
        sum+=a[i];
    }
    cout<<sum;
}