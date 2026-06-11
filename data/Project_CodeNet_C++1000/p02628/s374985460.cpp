/*
    Author: MEHXM
*/
#include <bits/stdc++.h>
using namespace std;

#define cp_io ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long int
#define oo 1000000010
#define MAX 1000000
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define nl "\n"

int main()
{
    cp_io;
    #ifndef ONLINE_JUDGE
    freopen("z_input.txt","rt",stdin);
    freopen("z_output.txt","wt",stdout);
    #endif
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    sort(a, a+n);
    ll ans = 0;
    for(int i=0; i<k; i++)
        ans += a[i];
    
    cout << ans << nl;
    
    return 0;
}