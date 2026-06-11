#include<iostream>
using namespace std;
long long power(long long a,long long b)
{
    if(b==0)
    {
        return 1;
    }
    else if(b%2==0)
    {
        return power((a*a),b/2);
    }
    else
    {
        return a*power((a*a),(b-1)/2);
    }
}
long long height(long long n)
{
    long long c=0;
    while(n>0)
    {
        c++;
        n=n>>1;
    }
    return c;
}
int main()
{
    long long n,b;
    cin>>n;
    b=height(n);
    cout<<power(2,b)-1<<endl;
    return 0;
}
