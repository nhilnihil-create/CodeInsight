#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
typedef pair<ll,ll> ipair;
#define F first
#define S second

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    
	ll n,i,j,p,k,m,ans=0,x,y;
    cin>>n>>x>>y;
    vector<ll> a(n,0);
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            m=min(j-i, abs(x-i)+1+abs(y-j));
            a[m]++;
        }
    }
    for(i=1;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    
	return 0;
}