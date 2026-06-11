#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238463;
const int MAXN = 1000030;
bool isPrime[MAXN];
vector<ll> ans;
void sieve()
{
    memset(isPrime, 1, sizeof isPrime);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= MAXN; i += 1 + (i & 1))
    {
        if (isPrime[i])
        {

            for (int j = i * i; j < MAXN; j += i)
                isPrime[j] = 0;
        }
    }
    for(int i=0; i<MAXN; i++)
    {
        if(isPrime[i])
        {

            ans.push_back(i);
        }
    }
}

int main()
{
    FAST
    ll n;
    cin>>n;
    ll temp=n;
    ll cnt=0;

    for(ll j=2; j*j<=temp; j++)
    {
        if(temp%j==0)
        {
            ll c=0;
            while(temp % j == 0)
            {
                c++;
                temp /= j;
            }
            ll sum=0;
            for(int i=1;; i++)
            {
                sum+=i;
                if(sum>c)
                {
                    cnt+=(i-1);
                    break;
                }
            }

        }
    }
    if(temp>1)
        cnt++;

    cout<<cnt<<endl;

    return 0;
}
