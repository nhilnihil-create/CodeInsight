#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const int mx=1e6+11;
const double PI = acos(-1);
#define MOD 1000000007


#define nl '\n'
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair

#define sz(x) x.size()
#define tt int t; cin>>t; while(t--)
#define lo(i,a,b) for(int i=a;i<b;i++)
#define rlo(i,n) for(int i=n-1;i>=0;i--)
#define be(a) (a).begin(),(a).end()
#define rbe(a) (a).rbegin(),(a).rend()
#define mem(a,b) memset(a,b,sizeof(a))
#define pr(a) {for(auto x:a)cout<<x<<" ";cout<<nl;}

#define su ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define frac cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu ()
{
    cerr << endl;
}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest)
{
    cerr << arg << ' ';
    faltu(rest...);
}

void f()
{
    ll n,a,b,p,ans=1;
    cin>>n>>a>>b;
    if(a==0)
    {
        cout<<0<<nl;
        return;
    }
    if(n<=a && n<=a+b)
    {
        cout<<n<<nl;
        return;
    }
    if(n>=a && n<=a+b)
    {
        cout<<a<<nl;
        return;
    }
    p=n/(a+b);
    n%=(a+b);
    ans=p*a;
    if(n<=a)
      ans+=n;
    else
      ans+=a;
    cout<<ans<<nl;
}

int main()
{
    su;
    ///tt
    f();
    return 0;
}
