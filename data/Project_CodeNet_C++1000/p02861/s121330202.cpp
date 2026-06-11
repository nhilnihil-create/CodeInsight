#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int fac[9];
    fac[0]=1;
    for (int i=1;i<=8;i++)
    fac[i]=(fac[i-1]*i);
    int n;
    scanf("%d",&n);
    int x[n];
    int y[n];
    for (int i=0;i<n;i++)
    scanf("%d%d",&x[i],&y[i]);
    vector<double> v;
    double sum1=0.0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            double val=sqrt(1.0*(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)));
            v.push_back(val);
        }
    }
    for (int i=0;i<v.size();i++)
    sum1=sum1+v[i];
    double k=((n-1)*fac[n])/(1.0*v.size());
    sum1=1.0*sum1*k;
    sum1=sum1/(1.0*fac[n]);
    cout<<fixed<<setprecision(10)<<sum1<<endl;
    return 0;
}