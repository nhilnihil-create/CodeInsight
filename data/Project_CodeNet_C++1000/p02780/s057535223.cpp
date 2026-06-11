#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vpli vector<pair<long long, int>>
#define deb(x) cout <<"deb "<<#x<<" "<< x << endl;
#define all(x) x.begin(), x.end()
ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<double> a(n);
    for(double& x : a)
    {
        cin>>x;
        x = (x+1)/2;
    }
    int l=0;
    double best_ans = 0;
    double run_ans = 0;
    for(int r=0;r<n;r++)
    {
        run_ans = run_ans+a[r];
        if(r>=k)
        {
            run_ans -= a[l++];
        }
        best_ans = max(best_ans,run_ans);
    }
    
    cout<<fixed<<setprecision(12)<<best_ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}