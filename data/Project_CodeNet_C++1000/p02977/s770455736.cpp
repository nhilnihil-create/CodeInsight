#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int ll
//#define endl '\n'

int n;

int32_t main()
{
    IOS
    cin>>n;
    for (int i=0;i<=20;i++)
    {
        if ((1<<i)==n)
        {
            return cout<<"No"<<endl,0;
        }
    }
    cout<<"Yes"<<endl;
    cout<<"1 2\n2 3\n";
    cout<<n+1<<' '<<n+2<<'\n';
    cout<<n+2<<' '<<n+3<<'\n';
    cout<<3<<' '<<n+1<<'\n';
    for (int i=5;i<=n;i+=2)
    {
        cout<<i-1<<' '<<i<<'\n';
        cout<<i<<' '<<n+1<<'\n';
        cout<<n+1<<' '<<n+i-1<<'\n';
        cout<<n+i-1<<' '<<n+i<<'\n';
    }
    if (n%2==0)
    {
        cout<<n<<' '<<n-1<<endl;
        int now=((n-1)^n^1);
        cout<<now+n<<' '<<2*n<<endl;
    }
}

