#include<bits/stdc++.h>
using namespace std;
#define read FILE *fp;\
fp=freopen("testcase.txt","r",stdin);
#define ll long long
#define ull unsigned long long
#define sf(n) scanf("%I64d",&n)
#define pf(n) printf("%I64d\n",n)
#define loop for(long long i=0;i<n;i++)
#define lp(b,n) for(long long i=b;i<=n;i++)
#define pb(n) push_back(n)
#define srt(v) sort(v.begin(),v.end())
#define rvs(v) sort(v.begin(), v.end(), greater<long long>());
#define F first
#define S second
#define mp(a,b) make_pair(a,b);
#define fio ios::sync_with_stdio(false); cin.tie(),cout.tie();
ll llmax = numeric_limits<long long>::max();
ll llmin= numeric_limits<long long>::min();
ll mark[5010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(),cout.tie();
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll> >v;
    ll a=0,b=0,c=0,d=0,e=0;
    for(ll i=1;i<=n-2;i++)
    {
        a+=i;
    }
    if(k>a)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(ll i=2;i<=n;i++)
    {
        v.push_back(make_pair(1,i));
    }
    d=a-k;
    for(ll i=2;i<n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            if(d==0)
            {
                c=1;
                break;
            }
            d--;
            v.push_back(make_pair(i,j));
        }
        if(c)
            break;
    }
    cout<<v.size()<<endl;
    for(ll i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}

