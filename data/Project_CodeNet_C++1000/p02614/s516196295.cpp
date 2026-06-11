///*Bismillahir Rahmanir Rahim***///
/***Stay_Home_Stay_Safe***/
///**Author Thasin Sheikh**///
#include<bits/stdc++.h>
using namespace std;
#define MAX 1e6+10
#define MOD 1000000007
#define PI 3.14159265359
#define makefast__  ios_base::sync_with_stdio(false);
using ll=long long int  ;
using dl =double;
const int N = 2e5 + 10;
ll aarray[200000+10];
ll magic[101][101];
vector<ll>primes;
bool prime[1000001];
char a[8][8],b[8][8];
ll n,m,k;
ll ans=0;
ll solve()
{
    ll i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            b[i][j]=a[i][j];
        }
    }
    return 0;

}
void color(ll i,ll j)
{
    for(ll l=0;l<n;l++)
    {
        if(i&(1<<l))
        {
            for(ll y=0;y<m;y++)
            {
                b[l][y]='k';
            }
        }
    }
    for(ll l=0;l<m;l++)
    {
        if(j&(1<<l))
        {
            for(ll y=0;y<n;y++)
            {
                b[y][l]='k';
            }
        }
    }
    return ;
}
bool check()
{
    ll i,j,c=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(b[i][j]=='#')
                c++;
        }
    }
    if(c==k)
        return true ;
    else return false;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    makefast__
    string str;
    ll i,j,t;
    cin>>n>>m>>k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0; i<(1<<n); i++)
    {
        for(j=0; j<(1<<m); j++)
        {
            solve();
            color(i,j);
            if(check())
                ans++;

        }
    }
    cout<<ans<<endl;

    return 0;
}


