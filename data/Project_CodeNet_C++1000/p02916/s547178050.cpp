#include <bits/stdc++.h>

#define ll              long long
#define endl            '\n'
#define cd              cout << '\n';
#define ys              cout << "YES"; return;
#define no              cout << "NO"; return;
#define pii             pair<int,int>
#define IOS             ios::sync_with_stdio(0);
#define vi              vector<int>
#define vll             vector<long long int>
#define vpii            vector<pair<int,int>>
#define pb              push_back
#define in              insert
#define mp              make_pair
#define all(a)          a.begin(),a.end()
#define rall(a)         a.rbegin(),a.rend()
#define fr              first
#define sc              second
#define sz(a)           a.size()
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define buga(i,n,a)     cout << endl; for(i = 0; i < n; ++i) cout << a[i] << " "; cout << endl;
#define bugv(i,n,v)     cout << endl; for(i = 0; i < n; ++i) cout << v[i].first << " " << v[i].second << endl; cout << endl;

using namespace std;

void solve()
{
    int n, i, ans = 0;
    cin >> n;
    int a[n], b[n], c[n - 1];
    for(i = 0; i < n; ++i)
        cin >> a[i];
    for(i = 0; i < n; ++i) {
        cin >> b[i];
        ans+= b[i];
    }
    for(i = 1; i < n; ++i) {
        cin >> c[i];
    }
    //cout << ans << endl;
    for(i = 0; i + 1 < n; ++i) {
        if(a[i] + 1 == a[i + 1]) {
            ans+= c[a[i]];
        }
    }
    cout << ans;
}



int main()
{
    IOS;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}
