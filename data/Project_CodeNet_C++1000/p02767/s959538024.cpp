#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>


void test_case()
{
    int n;
    cin>>n;
    int sum=0,a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int avg=round((double)sum/n);
    ll ans=0;
    for(int i=0;i<n;i++) {
        ans+=1LL * (avg-a[i]) * (avg-a[i]);
    }
    cout<<ans;
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
