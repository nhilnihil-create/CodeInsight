#include<bits/stdc++.h>
using namespace std;

#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const long long int infLL = 9000000000000000000;

#define mem(a,b) memset(a, b, sizeof(a) )
#define all(a) (a).begin(),(a).end()
#define mx_int_prime 999999937
#define Size 100000000

const int inf = 2000000000;
const double PI = acos(-1);
const double eps = 1e-9;
typedef long double ld;

#define MOD 1000000007

typedef long long ll;
const int mx=2e5+125;

ll pr[mx],ar[mx],br[mx];

#define PB push_back
#define endl '\n'
#define S second
#define F first
bool p[Size];

void seive()
{
    mem(p,1);
    p[0]=0;
    p[1]=0;
    for(ll i=2; i*i<=Size; i++)
    {
        if(p[i]==1)
        {
            for(ll j=2*i; j<=Size; j+=i)
            {
                p[j]=0;
            }
        }
    }
    ll n;
    cin>>n;
    for(ll i=n; ; i++)
    {
        if(p[i]==1)
        {
            cout<<i<<endl;
            return ;
        }
    }
}
int main()
{
    seive();

    return 0;
}
