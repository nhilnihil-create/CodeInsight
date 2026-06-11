using namespace std;
#include <bits/stdc++.h>
#define frr(i, r, l) for(int i = r; i >= l; --i)
#define fr(i, l, r) for(int i = l; i < r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define MEMS(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define m_p make_pair
#define pb push_back
#define ll long long
#define ld long double
typedef pair<ll, ll> iPair; 
priority_queue< ll, vector <ll> , greater<ll>>pq1,pq2;
#define maxN 1000000000000000000
ll power(ll a,ll b){ll res=1;while(b>0){res*=a;b--;}return res;}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,y;
    cin>>n;

    ll mn1=maxN;
    ll mx1=-maxN;

    ll mn2=maxN;
    ll mx2=-maxN;
    ll ans;
    fr(i,0,n)
    {
        cin>>x>>y;
        ll sum1=x+y;
        ll sum2=x-y;
        mn1=min(mn1,sum1);
        mx1=max(mx1,sum1);

        mn2=min(mn2,sum2);
        mx2=max(mx2,sum2);
    }
    ans=max(mx2-mn2,mx1-mn1);
    cout<<ans<<endl;
    return 0;
}