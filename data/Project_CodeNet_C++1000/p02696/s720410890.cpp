#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,n,ans;
    double x;

    cin>>a>>b>>n;

    if(b-1 <= n) x = (double) (b-1.0) / (double) b;
    else x = (double) n / (double) b;

    ans = floor((double) a * x) - a * floor(x);    

    cout<<ans<<endl;
}