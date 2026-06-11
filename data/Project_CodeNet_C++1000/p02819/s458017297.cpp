#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

bool IsPrime(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)return false;
    }
        return n!=1;

}
int main()
{
    ll n;
    cin>>n;
    while(1)
    {
        if(IsPrime(n))
        {
            cout<<n<<endl;
            return 0;
        }
        n++;
    }
}
