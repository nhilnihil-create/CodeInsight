#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i;
    double w;
    cin>>n;
    if(n%2==0) i=n/2;
    else i=(n+1)/2;
     w=(double)(i)/(double)(n);
    cout<<fixed<<setprecision(10)<<w<<endl;

return 0;
}
