#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define loop(a,b)            for(ll i=a;i<=b;i++)
#define sci(n)               scanf("%d",&n)
#define scl(n)               scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define srt(g)               sort(g.begin(),g.end())
#define rvs(g)               reverse(g.begin(),g.end())
#define pl                   pair<long long,long long>
#define ll long long
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define f first
#define s second
int mod=2019;
int main()
{
    string s;
    cin >> s;
    vector<int>cnt(mod+10);
    ll ans=0;
    ll suf=0;
    cnt[suf]++;
    int p=1;
    for(ll i=s.size()-1;i>=0;i--)
    {
        int x=s[i]-'0';
        suf=(suf+x*p)%2019;
        p=10*p%2019;
        //cnt[suf]++;
        ans=ans+cnt[suf];
        cnt[suf]++;
    }
    cout << ans << "\n";
}
