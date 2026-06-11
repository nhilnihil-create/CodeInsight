#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N=2e5+5;
#define inf 1e18+8
const int mod=1e9+7;
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define vpii vector<pair<int,int> > 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


signed main()
{
    int n,m;
    cin>>n;
    vi arr(n);
    vi A(n);
    vi B(n);    
    //for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        cin>>A[i]>>B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    if (n&1)
    {
        cout<<(B[n/2]-A[n/2]+1)<<"\n";

    }
    else 
    { 
        cout<<B[n/2]+B[n/2-1]-A[n/2]-A[n/2-1]+1<<"\n";
    }



}

    
    