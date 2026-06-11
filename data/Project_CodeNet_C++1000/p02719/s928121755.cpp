#include<iostream>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
int main()
{
    long long int n,k;
    cin>>n>>k;
    n=min(n%k,abs(n%k-k));
    cout<<n;
}