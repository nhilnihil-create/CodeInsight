/**********************************************
*   UPDATE CONDITION & OVERFLOW CONDITION     *
**********************************************/

#include<bits/stdc++.h>
using namespace std;

#define pi 3.1415926535
#define endl "\n"
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define ll long long
#define llu unsigned long long
#define pb push_back
#define mp make_pair
#define tc int t; cin>>t; while(t--)
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define rf(i,n,a) for(int i=n-1 ; i>=a ; i--)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define get(a,n) f(i,0,n) cin >> a[i];
#define show(a,n) f(i,0,n) cout << a[i] << " "; cout << endl;
#define fast ios:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;

const int inf = 1e9;
const long long int inf64 = 1e18;
const int mod = inf + 7;
const int N = 2e5 + 10;

int main()
{
    fast;
    ll n, ans = 0;
    cin >> n;
    map<ll, ll> mp;
    for(ll i=1;i<=n;i++)
    {
        ll x;
        cin >> x;

        ans += mp[i-x];

        mp[i+x]++;
    }

    cout << ans;
}

