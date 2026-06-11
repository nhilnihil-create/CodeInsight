#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define en "\n"
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define mpp make_pair
#define mes(a,b) memset((a),(b),sizeof((a))
typedef map<int,int> MI;
typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        long long int n,m,x;
        cin>>n>>m>>x;
        long long int a[n],b[m];
        for(long long int i=0;i<n;i++)
        cin>>a[i];
        for(long long int i=0;i<m;i++)
        cin>>b[i];
        
        long long int k=0,i=0;
        while(i<n && k+a[i]<=x)
        {
            k=k+a[i];
            i++;
        }
        long long int ans=i,j=0;
        
        long long int sum=k;
        while(j<m && i>=0)
        {
            sum=sum+b[j];
            j++;
            while(sum>x && i>0)
            {
                i--;
                sum=sum-a[i];
            }
            if(sum<=x && i+j>ans)
            ans=(i+j);
        }
        cout<<ans<<en;
    
    return 0;
}
