#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
    int x,n,p,a,b;
    bool m[105]= {0};
    cin>>x>>n;
    if(n==0)
    {
        cout<<x<<nl;
        return;
    }
    while(n--)
    {
        cin>>p;
        m[p]=1;
    }
    for(int i=x;; i++)
    {
        if(m[i]==0||i>100)
        {
            b=i;
            break;
        }
    }
    for(int i=x;; i--)
    {
        if(m[i]==0||i<0)
        {
            a=i;
            break;
        }
    }
    if(abs(x-a)<abs(x-b))
        cout<<a<<nl;
    else if(abs(x-a)>abs(x-b))
        cout<<b<<nl;
    else
    {
        if(a<b)
            cout<<a<<nl;
        else
            cout<<b<<nl;
    }
}

int main()
{
    su;
    ///tt
    f();
    return 0;
}
