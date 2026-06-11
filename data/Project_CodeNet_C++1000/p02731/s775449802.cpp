#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define endl "\n"

int main() {
    int t=1;
    // cin>>t;
    while(t--)
    {
        long double n,a,ans;
        cin>>n;
        a=n/3;
        ans=a*a*a;
        cout<<setprecision(13)<<ans<<endl;
    }
}
