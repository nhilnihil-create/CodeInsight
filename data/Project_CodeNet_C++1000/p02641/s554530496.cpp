#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define float long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define endl '\n'
#define pii pair<int, int>
#define min3(a,b,c) min(a, min(b, c))
#define max3(a,b,c) max(a, max(b, c))
#define all(x) x.begin(), x.end()
#define fill(a,b) memset(a, b, sizeof(a))
#define sz(x) (int)x.size()
#define sp(x) setprecision(x)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x,n; cin>>x>>n;
    set<int> s; s.insert(x);
    for(int i=1;i<105;i++){
        s.insert(x+i);
        s.insert(x-i);
    }
    for(int i=0;i<n;i++){
        int y; cin>>y;
        if(s.find(y)!=s.end()) s.erase(y);
    }
    int ans=0,ans1=105;
    for(int it : s){
        if(abs(it-x)<ans1){
            ans1=abs(it-x);
            ans=it;
        }
    }
    cout<<ans<<endl;

}