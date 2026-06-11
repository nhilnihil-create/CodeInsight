#pragma GCC optimize("O3")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); ++i)
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second

ll mod=1e9+7;

ll fact(int n)
{
    ll tot=1;
    FOR(i,1,n+1)
    {
        tot=(tot*i)%mod;
    }
    return tot;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s[0]=='W' || s[sz(s)-1]=='W')
    {
        cout << 0;
        return 0;
    }
    vector<int> cs(sz(s));
    cs[0]=0;
    cs[sz(s)-1]=1;
    FOR(i,1,sz(s)-1)
    {
        if(s[i]==s[i-1])
            cs[i]=1-cs[i-1];
        else
            cs[i]=cs[i-1];
    }
    int sum=0;
    F0R(i,sz(s))
    {
        sum+=cs[i];
    }
    if(sum!=sz(s)/2)
    {
        cout << 0;
        return 0;
    }
    vector<int> nl(sz(s),0), nr(sz(s),0);
    nl[0]=1;
    nr[0]=0;
    FOR(i,1,sz(nl))
    {
        if(cs[i]==0) nl[i]=nl[i-1]+1;
        else nl[i]=nl[i-1];
    }
    FOR(i,1,sz(nr))
    {
        if(cs[i]) nr[i]=nr[i-1]+1;
        else nr[i]=nr[i-1];
    }
    ll tot=1;
    ll cnt=0;
    F0R(i,sz(cs))
    {
        if(cs[i])
        {
            tot=((tot*(nl[i]-cnt))%mod);
            cnt++;
        }
    }
    tot=((tot*fact(sz(s)/2))%mod);
    cout << tot;

    return 0;
}
