#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REV(i,a,n) for(int i=a;i>=n;i--)
#define all(a) a.begin(),a.end()
const int NUM = 2e5 + 5;

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num_tests=1; 
    //cin >> num_tests;
    while(num_tests-->0){
        int n,m,x; cin >> n >> m >> x;
        vector<int> cost(n);
        int skills[n][m];
        FOR(i,0,n)
        {
            cin >> cost[i];
            FOR(j,0,m) cin >> skills[i][j];
        }
        int ans = 1e18;
        int bit = (1 << n);
        FOR(i,0,bit)
        {
            int val = 0;
            vector<int> learnt(m,0);
            FOR(j,0,n)
            {
                if(i & (1 << j))
                {
                    val += cost[j];
                    FOR(k,0,m)
                        learnt[k] += skills[j][k]; 
                }
            }
            bool ok = 1;
            FOR(j,0,m)
                if(learnt[j] < x)
                {
                    ok = 0; break;
                }
            if(ok)
                ans = min(ans,val);
        }
        if(ans == 1e18)
            cout << -1;
        else
            cout << ans ;
    }    
}