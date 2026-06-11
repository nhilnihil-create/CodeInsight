#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double ans;
    if(n%2==0)
    {
        ans=0.5;
    }else
    {
        double a=n/2;
        a++;
        ans=a/(double)n;
    }
    cout<<fixed<<setprecision(7)<<ans<<endl;
}