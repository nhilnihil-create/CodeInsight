/*..........AAKASH GOYAL............*/
/*............DAIICT................*/
 
#include <bits/stdc++.h>
using namespace std;

#define    int                      long long int

#define    f(i,j,n)                 for(int i = j; i <= n; i++)
#define    r(i,n,j)                 for(int i = n; i >= j; i--)
#define    mod                      1000000007
#define    speed                    ios_base::sync_with_stdio(false);
#define    upp                      cin.tie(NULL);
#define    pb                       push_back
#define    mp                       make_pair
#define    T                        int tt; cin >> tt; while(tt--)
#define    ff                       first
#define    ss                       second
#define    all(container)           container.begin() , container.end()
#define    sz(container)            (int)container.size()
#define    pii                      pair <int , int>
#define    ppi                      pair <int , pii>               
#define    sp(x)                    setprecision(x)
  
int32_t main()
{
    speed upp
    int n,m,v,p,ans,sum=0;
    cin>>n>>m>>v>>p;
    int a[n+1];
    f(i,1,n)
        cin>>a[i];
    sort(a+1,a+n+1);
    v=v-p;
    v=max((int)0,v);
    int l=1,r=n-p;
    ans=r+1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(a[mid]+m<a[n-p+1])
            l=mid+1;
        else
        {
            sum=0;
            f(i,1,n-p+1)
            {
                if(i==mid)
                    continue;
                int x=a[mid]+m-a[i];
                x=min(m,x);
                sum+= x;
                
            }
            
            if ( v*m  <= sum )
            {
                r=mid-1;
                ans=mid;
            }
            else    
                l=mid+1;
        }
    }
    
    cout<<n-ans+1;
}