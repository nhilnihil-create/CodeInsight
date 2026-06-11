#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
#define ll long long int
#define pi 3.141592653589793238
const int N = 1e5 + 10;
int main(){
    FAST;
    ll t=1;
    // cin>>t;
    while(t--)
    {
        ll n,ans=0;
        cin>>n;
        vector<int> p(n+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j*i<=n;j++)
                p[i*j]++;
        for(int c=1;c+1<=n;c++)
            ans+=p[c];
        cout<<ans;
    }
    return 0;
}
