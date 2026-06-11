#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fr first
#define sc second
#define N 300009
#define inf 2e16
#define pi pair<ll,ll>
#define pb push_back
using namespace std;
typedef long long ll;
void slv()
{
    int n;
    cin>>n;
    for(int i=1;i<=9;i++) {
        if(n%i==0)
        {
            int d=n/i;
            if(d>0 && d<10) 
            {
                puts("Yes");
                return ;
            }
        }
    }
    puts("No");
}
int main()
{
    ll tt;
    tt=1;
    while (tt--)
    {
        slv();
    }
    return 0;
}
