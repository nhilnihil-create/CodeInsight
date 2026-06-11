#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1000000007;
const ll N=1e5+9;
int main()
{
    FASTINOUT;
    ll x,k;
    cin>>x>>k;
    ll m=(x-1)*(x-2)/2;
    if (m<k)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<x-1+m-k<<endl;
    for (int i=2; i<=x; i++)
        cout<<1<<" "<<i<<endl;
    int f=2,s=3;
    for (int i=0;i<(x-1)*(x-2)/2-k;i++)
    {
        if (s>x){
            f++;
            s=f+1;
        }
        cout<<f<<" "<<s<<endl;
        s++;
    }
    return 0;
}
