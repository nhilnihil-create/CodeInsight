#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#define l(i,a,b) for(auto i=a;i<b;i++)
#define lr(i,a,b) for(auto i=a;i>=b;i--)
#define ll long long
#define lli long long int
#define ld long double
#define vec vector<int>
#define mii map<ll,ll>
#define vl vector<long long>
#define se set <long long int>
#define pi pair<long long,long long>
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define in(x) cin>>x
#define o(x) cout<<x
#define SYNC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI 3.14159265359
using namespace std;

const int MAX = 1e6 + 5;
int factorial[MAX];
bool ok=false;

void fac(ll k)
{
    if(ok)
    {
        return;
    }
    for(ll i=1; i<=sqrt(k); i++)
    {
        if(k%i==0)
        {
            ll a = k/i;
            ll b = i;

            if(a==b)
            {
                b=1;
            }

            if(a!=1)
            {
                if(factorial[a])
                {
                    ok=true;
                    return;
                }
                factorial[a]++;
            }
            if(b!=1)
            {
                if(factorial[b])
                {
                    ok=true;
                    return;
                }
                factorial[b]++;
            }
        }
    }
}


int main()
{
    SYNC
    //clock_t tStart = clock();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n; in(n);
    vl v(n);
    l(i,0,n)
    {
        in(v[i]);
    }
    ll check = v[0];
    l(i,1,n)
    {
        fac(v[i]);
        check = __gcd(check,v[i]);
    }
    if(!ok)
    {
        o("pairwise coprime");
    }
    else if(check==1)
        o("setwise coprime");
    else
        o("not coprime");








    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);   
}
