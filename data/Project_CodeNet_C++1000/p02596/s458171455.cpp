#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
bool ar[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,t,n,b,a,c,d,l,r;
    cin>>n;
        x=0;
        ll cnt=1;
        while(1)
        {
            x*=10;
            x+=7;
            x%=n;
            if(ar[x])
                break;
            if(x==0)
            {
                cout<<cnt<<'\n';
                return 0;
            }
            ar[x]=1;
            cnt++;

        }
        cout<<-1<<'\n';
}








