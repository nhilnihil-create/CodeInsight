//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

#include<bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define ins insert
#define pi  3.14159265359
#define mod 1000000007
#define si(x) int(x.size())
#define FOOR(i, a, b)  for (int i=a; i<=(b); i++)
#define FOR(i, a)  for (int i=0; i<(a); i++)
#define FOORd(i,a,b)  for (int i = (b)-1; i >= a; i--)
#define FORd(i,a)  for (int i = (a)-1; i >= 0; i--)

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>w;
    vector<int>r;
    for(int i=0;i<si(s);i++)
    {
        if(s[i]=='R')
            r.push_back(i+1);
        else
            w.push_back(i+1);
    }
    int ans=0;
    sort(all(r),greater<int>());
    for(int i=0;i<min(si(r),si(w));i++)
    {
            if(r[i]>w[i]){
             ans++;
            }

    }
        cout<<ans<<endl;
}

















