#include <bits/stdc++.h> 
using namespace std;
#define int long long int
#define float double
#define pb push_back
#define FF first
#define SS second
#define N 100005
#define MOD 1000000007
#define fn(i,n) for(int i=0;i<n;i++)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>
#define mp make_pair
#define INF 1000000000000000000
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

signed main() 
{
    speed;
    //freopen("input.tXt","r",stdin);
    //freopen("output.tXt","w",stdout);
    
    int n;
    cin>>n;
    int A[n+1];
    map<int,int> m1,m2;
    for(int i=1;i<=n;i++) 
    {
        cin>>A[i];
        m1[i+A[i]]++;
        m2[i-A[i]]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        ans+=m2[i+A[i]];
        //cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}   