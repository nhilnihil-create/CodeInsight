#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define maxn 120
#define name "bai1"
ll m,d,res;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);

    cin>>m>>d;
    f(i,1,m)
    {
        f(j,1,d)
        {
            ll x=j%10;
            ll y=(j-x)/10;
            if(x>=2 && y>=2 && x*y==i)
            {
                res++;
            }
        }
    }
    cout<<res;
}
