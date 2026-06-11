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
    
    int k,n;
    cin>>k>>n;
    int A[n+1];
    for(int i=1;i<=n;i++) cin>>A[i];
    int minn=INT_MAX;
    for(int i=1;i<=n;i++) 
    {
        if(i==n) minn=min(minn,min(A[n]-A[1],k+A[n-1]-A[n]));
        else minn=min(minn,min(k-A[i+1]+A[i],2*(A[i]-A[1])+(A[n]-A[i])));
    }
    cout<<minn<<endl;
}   