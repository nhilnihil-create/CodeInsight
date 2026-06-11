#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for1(n) for(i=1; i<=(n); i++)
#define N 10000
bool isPrime[N];

vector<ll> prime;

void seive()
{
    ll i,j,t=1,val;
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    for(i=4;i<=N;i+=2) isPrime[i]=false;
    for(i=3;i*i<=N;i+=2)
        if(isPrime[i])
            for(j=i*i;j<=N;j+=2*i )
                isPrime[j]=false;
    for(i=2;i<=N;i++)
        if(isPrime[i])
            prime.push_back(i);
}

ll primefactorization(ll n)
{
    ll c=1,i,j,cc;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            cc=1;
            while(n%prime[i]==0)
            {
                n/=prime[i];cc++;
            }
            c*=cc;
        }
    }
    if(n>1) c*=2;
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _,i,j,n,a,b,e,k,u,t,x=1,m,y,q,f=1,c=0,d=0,l,p,z,o,r,g;
    string ss,s;
    seive();
    cin>>n;
    for1(n-1)
    {
        x=n-i;
        p=primefactorization(x);
        c+=p;
    }
    cout<<c<<endl;
}

