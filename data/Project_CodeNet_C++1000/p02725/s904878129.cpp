#include <bits/stdc++.h>
#define int long long int
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>k>>n;
    int t,t2;
    int s=0;
    int maxi=INT_MIN;
    int f;
    cin>>s;
    f=s;
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>t;
        t2=t;
        t = t-s;
        sum +=t;
        maxi = max(maxi,t);
        s=t2;
    }
    
    maxi = max(maxi,k-sum);
    cout<<k-maxi;
    return 0;
}