#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define initdp(a, b)  for (int i = 0; i <= a; i++)   for (int j = 0; j <= b; j++) dp[i][j] = -1;
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define inf 1000000001
#define inf1 1000000000000000001
#define mod 1000000007
#define pie 3.14159265358979323846
#define N 1000005
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define umapi unordered_map<ll, ll>
#define umapc unordered_map<char, int>
#define endl "\n"
using namespace std;

/*
            ॐ
    || Jai Shree Ram ||  
 
 */

void solve()
{
   
    ll n,m,k;
    cin>>n>>m>>k;
 
    vecl a(n+1);
    a[0] = 0;
    ll sum= 0;
    fo(i,1,n) {
        ll x;
        cin>>x;
 
        sum+= x;
        a[i] = sum;
    }
 
    vecl b(m+1);
    b[0] = 0;
    sum=0;
 
    fo(i,1,m) {
        ll x;
        cin>>x;
 
        sum+= x;
        b[i] = sum;
    }
    ll ans  =0;
    for(ll i=0; i<=n; i++) {
        ll val = k - a[i];
        if(val<0) {
            break;
        }
        if(val==0) {
            ans = max(ans, i);
            break;
        }
 
        int temp = lower_bound(all(b),val) - b.begin();
        if(temp>m || b[temp] > val) {
            temp--;
        }
        ans = max(ans, i+temp);
    }
 
    cout<<ans<<endl;
 
 
 
 
}


// void solve()
// {
   
//     int n,m,k;
//     cin>>n>>m>>k;

//     vec a(n+1);
//     a[0] = 0;
//     int sum= 0;
//     fo(i,1,n) {
//         int x;
//         cin>>x;

//         sum+= x;
//         a[i] = sum;
//     }

//     vec b(m+1);
//     b[0] = 0;
//     sum=0;

//     fo(i,1,m) {
//         int x;
//         cin>>x;

//         sum+= x;
//         b[i] = sum;
//     }
//     int ans  =0;
//     int j= m;
//     for(int i=0; i<=n; i++) {
//         if(a[i] > k) {
//             break;
//         }

//         while(b[j] > k-a[i] && j>=0) {
//             j--;
//         }
//         ans = max(ans, i+j);
//     }

//     cout<<ans<<endl;




// }
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
