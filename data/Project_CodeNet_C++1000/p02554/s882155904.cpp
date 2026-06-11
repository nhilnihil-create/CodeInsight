#include <iostream>
using namespace std;

long long int modPow(long long int a,long long int b,long long int mod)
{
    if(b==0)
        return 1;
    long long int p = modPow(a,b/2,mod)%mod;
    p=(p*p)%mod;
    return (b%2==0)? p : (a*p)%mod;
}

int main()
{
    int N {};
    const long long int mod {static_cast<long long int>(1e9+7)};
    cin >> N;
    if(N==1)
        cout << 0;
    else
    {
        long long int ans=(modPow(10,N,mod)-modPow(9,N,mod)-modPow(9,N,mod)+modPow(8,N,mod))%mod;
        cout << (ans+mod)%mod;
    }
    return 0;
}