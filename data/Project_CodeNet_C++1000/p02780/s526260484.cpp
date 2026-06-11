#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin>>n>>k; double p[n], s[n+1];
    double sum = 0;

    for(int i=0; i<n; i++) {
        cin>>p[i];
        p[i] = 1.0*(1+p[i])/2;
        sum += p[i];
        s[i+1] = sum;
    }
    
    double ans = 0;
    for(int i=0; i<n-k+1; i++) {
        ans = max(ans, s[i+k] - s[i]);
    }
    cout<<fixed<<setprecision(8)<<ans;
    return 0;
}