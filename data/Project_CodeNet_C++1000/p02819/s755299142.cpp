#include<bits/stdc++.h>
using namespace std;
#define M 1000002
vector<long long >primes;
bool marked[M];

void sieve(long long  n)
{

    for (long long  i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == false)   // i is a prime
        {
            for (long long  j = i * i; j <= n; j += i )
            {
                marked[j] = true;
            }
        }
    }
    primes.push_back(2);
    for(long long i=3; i<=n; i+=2)
    {
        if(marked[i]==false)
            primes.push_back(i);
    }
}

int main()
{
    long long  n;
    cin>>n;
    sieve(100500);

    vector<long long>:: iterator it = lower_bound(primes.begin(),primes.end(),n);
    cout<<*it<<endl;

    return 0;
}
