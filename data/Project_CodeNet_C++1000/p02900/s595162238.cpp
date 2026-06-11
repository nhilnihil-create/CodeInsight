#include<iostream>
using namespace std;
const int N=1e5+10;
typedef long long LL;

LL prime[1000],num[1000],cnt;

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

void divide(LL x)
{
    for (LL i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            LL s = 0;
            while (x % i == 0) x /= i, s ++ ;
            prime[cnt]=i,num[cnt++]=s;
        }
    if (x > 1) prime[cnt]=x,num[cnt++]=1;
}

int main()
{
    LL a,b;
    cin>>a>>b;
    LL g=gcd(a,b);
    divide(g);
    cout<<cnt+1<<endl;
    //system("pause");
}