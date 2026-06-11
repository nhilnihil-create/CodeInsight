#include<iostream>
using namespace std;

long long int big_mod(long long  b, long long  p, long long m)
{
    long long int power=b%m,re=1;
    while(p!=0)
    {
        if(p%2==1) re=(power*re)%m;
        power=(power*power)%m;
        p/=2;
    }
    return re;
}

int main()
{
    long long int n,ten,eight,nine,re;
    cin >>n;
    ten= big_mod(10,n,1000000007);
    nine= big_mod(9,n,1000000007);
    eight= big_mod(8,n,1000000007);
    re=((ten-((2*nine)%1000000007)+ eight)%1000000007);
    if(re<0) re+=1000000007;
    cout << re;
}
