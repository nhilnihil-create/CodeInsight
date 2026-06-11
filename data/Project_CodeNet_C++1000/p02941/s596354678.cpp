/*
 _     _    ___  ___  __ __ 
| |   | |  |__ \|__ \/_ /_ |
| |__ | |__   ) |  ) || || |
| '_ \| '_ \ / /  / / | || |
| |_) | |_) / /_ / /_ | || |
|_.__/|_.__/____|____||_||_|

*/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

#define N  100005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        ll n;
        cin>>n;
        vi a,b;
        rep(i,0,n)
        {
            ll x;
            cin>>x;
            a.pb(x);
        }
        priority_queue < pii, std::vector<pii>, std::less<pii> > mxheap;
        rep(i,0,n)
        {
            ll x;
            cin>>x;
            b.pb(x);
            mxheap.push({x,i});
        }
        ll ans=0;
        // mxheap.push(), mxheap.top(), mxheap.pop()
        while(!mxheap.empty())
        {
            pii p=mxheap.top();
            ll i=p.S;
            ll s=b[(p.S+1)%n]+b[(p.S+n-1)%n];
            mxheap.pop();
            if((b[i]-a[i])%s==0)
            {
                ans+=(b[i]-a[i])/s;
                b[i]=a[i];
                continue;
            }
            if(s>=b[i])
            {
                cout<<-1<<endl;
                return 0;
            }
            ans+=b[i]/s;
            b[i]%=s;
            if(b[i]<a[i])
            {
                cout<<-1<<endl;
                return 0;
            }
            mxheap.push({b[i],i});
        }
        cout<<ans<<endl;
    
    }
    return 0;
}