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
#define inf 10000000000000005LL

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k; cin>>n>>k;
    int p[n],c[n],ans=-inf;
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]--;
    }
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++){
        vector<int> v;
        int j=i,ans1=-inf,a=-inf,b=-inf;
        while(p[j]!=i){
            j=p[j];
            v.pb(c[j]);
        }
        v.pb(c[i]);
        for(int l=1;l<sz(v);l++) v[l]+=v[l-1];
        // for(int x : v) cout<<x<<" "; cout<<endl;
        for(int l=0;l<sz(v);l++){
            if(l<k%sz(v)) a=max(a,v[l]);
            b=max(b,v[l]);
        }
        // cout<<a<<" "<<b<<endl;
        ans1=a;
        if(k>=sz(v)) ans1=max3(ans1,a+v.back()*(k/sz(v)),b);
        if(k>=2*sz(v)) ans1=max(ans1,v.back()*((k/sz(v))-1)+b);
        ans=max(ans,ans1);
    }
    cout<<ans<<endl;

}