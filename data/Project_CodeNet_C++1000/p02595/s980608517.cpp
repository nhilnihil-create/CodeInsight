#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
#define sf(x) scanf("%d",&x)
#define sfl(x) scanf("%lld",&x)
#define lli long long int
#define ll64 int64_t
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define frr(i,a) for(int i=0;i<a;i++)
#define frl(i,a) for(lli i=0;i<a;i++)
int main()
{
    lli n;
    double d;
    cin>>n>>d;
    double p,q;
    lli c=0;
    frr(i,n)
    {
        cin>>p>>q;
        double x=sqrt(p*p+q*q);
        if(x<=d)
        {
            c++;
        }
    }
    cout<<c<<endl;
}
