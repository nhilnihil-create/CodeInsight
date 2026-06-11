#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const int Mx=1e6+11;
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
#define be(a) (a).begin(),(a).end()
#define rbe(a) (a).rbegin(),(a).rend()
#define mem(a,b) memset(a,b,sizeof(a))
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl

#define su ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define frac cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

void f()
{
    int n,x,cnt=0;
    cin>>n>>x;
    int a[n+2]= {0};
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]=a[i]+a[i-1];
    }
    for(int i=0; i<=n; i++)
    {
        if(a[i]<=x)
            cnt++;
    }
    cout<<cnt<<nl;
}

int main()
{
    su;
    f();
    return 0;
}
