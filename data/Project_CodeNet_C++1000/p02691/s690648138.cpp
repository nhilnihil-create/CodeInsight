#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<long long> vll;
typedef vector<pii> pxx;
typedef vector<int> vi;
#define pb push_back
#define mod  1000000007
#define PI 2*acos(0.0)
#define REP(i,a,b)  for(i = a; i <= b; i++)
#define f(a,b)  for(a=0 ; a<b; a++)



main()
{
    ll t=1;//cin>>t;
    while(t--)
    {
        ll n,i,sum=0,x,c=0,ec=0;
        cin >> n;
        ll ara[300000];
        map<ll,ll> v;
        f(i,n)
        {
            cin >> x;
            x=i-x+1;
            ara[i]=x;
            v[x]++;
        }
        f(i,n)
        {
            x=2*(i+1)-ara[i];
            sum+=v[x];
        }
        cout << sum << endl;


    }
}
