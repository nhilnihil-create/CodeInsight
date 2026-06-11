#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define tc int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vll vector<lli>
#define vpi vector<pair<int,int> > 
#define vpll vector<pair<lli,lli> > 
#define vvi vector<vector<int> >
#define vvll vector<vector<lli> >
#define maxn 500005
#define mod 1000000007
#define inf 10000000000000000
 
 
 
int main()
{
    fastio;
    int n,k;
    cin>>n>>k;
    vi p(n),c(n);
    for(int i=0;i<n;i++)
    cin>>p[i],p[i]--;
    for(int i=0;i<n;i++)
    cin>>c[i];
    bitset<5001> fr;
    lli ans=-1e15;
    for(int i=0;i<n;i++)
    {
        int st=p[i];
        vi cur;cur.pb(st);
        while(st!=i)
        {
            st=p[st];
            cur.pb(st);
        }
        int n1=cur.size();
        lli tot=0,pm=-1e15,pm2=-1e15;
        lli num=k/n1;
        lli rem=k%n1;
        for(int i=0;i<n1;i++)
        {
            if(i<k) tot+=c[cur[i]],ans=max(ans,tot),pm=max(pm,tot);
            if(i<rem) pm2=max(pm2,tot);
        }
        if(num!=0)
        ans=max(ans,num*tot+max(pm2,0ll));
        if(num>=1)
        ans=max(ans,(num-1)*tot+pm);
    }
    cout<<ans<<"\n";
    return 0;
}