#include <bits/stdc++.h>
#define VI vector<int> 
#define SI set<int>
#define QI queue<int> 
#define PII pair<int, int>
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define F for(int i = 0; i < n; ++i)
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define M 1000000007
using namespace std;

int main() 
{
    int n,m,k; cin>>n>>m>>k;
    vector<ll> a(n+1),b(m+1);
    REP(i,1,n+1) {cin>>a[i]; a[i] += a[i-1]; }
    REP(i,1,m+1) {cin>>b[i]; b[i] += b[i-1]; }

    int ans=0;

    for (int i = 0; i <= n; ++i)
    {
        int selb=1;
        if(k - a[i] >= 0) {
            selb = upper_bound(b.begin(),b.end(),k-a[i]) - b.begin();
            ans = max(ans,i+selb-1);
        } 
    }

    cout<<ans<<endl;

    return 0;
}