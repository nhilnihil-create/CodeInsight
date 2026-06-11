#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define tc int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vll vector<lli>
#define maxn 300005
#define mod 1000000007
 
 
int main()
{
    fastio;
    int x;
    cin>>x;
    int t1=360,t2=x;
    int an=1;
    for(int i=2;i<=sqrt(t2);i++)
    {
        int c1=0,c2=0;
        while(t2%i==0)
        {
            c1++;
            t2/=i;
        }
        while(t1%i==0)
        {
            t1/=i;
            c2++;
        }
        if(c1>c2)
        {
            an*=pow(i,c1-c2);
        }
    }
    if(t2>1)
    {
        if(t1%t2!=0)
        an*=t2;
    }
    cout<<(an*360)/x<<"\n";
    return 0;
}