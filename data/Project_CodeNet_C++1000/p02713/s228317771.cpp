#include<iostream>
#include<bitset>
#include<numeric>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
int main()
{
    int n,ans=0;
    cin>>n;
    rep(i,n) rep(k,n) rep(j,n)
    {
        ans+=gcd(gcd(i,k),j);
    }
    cout<<ans;
}