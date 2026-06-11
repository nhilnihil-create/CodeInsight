
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

#define pi 2*acos(0.0)
#define eps 1e-9
const int N = 10000000;
bool isprime[N+1];

void sieve()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;

    for(ll i=2; i*i<=N; i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i; j<=N; j+=i)
            {
                isprime[j]=false;
            }
        }
    }
}


int main(void)
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);


    string s;
    cin>>s;
    if(s[2]==s[3] && s[4]==s[5])
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }



}

