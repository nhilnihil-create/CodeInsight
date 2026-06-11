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
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int mx=a[0], ans=1;
    for(int i=1;i<n;i++) {
        if(a[i]<=mx) {
            ans++;
            mx=min(mx,a[i]);
        }
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
