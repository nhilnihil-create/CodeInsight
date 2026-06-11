#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    double d=0,s=0,x1=0,y1=0;
    cin>>n;
    int x[n],y[n];
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    vector<double>v;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            x1=(double)pow((x[i]-x[j]),2);
            y1=(double)pow((y[i]-y[j]),2);
            d=sqrt(x1+y1);
            v.push_back(d);
        }
    }
    for(int i=0;i<v.size();i++)
    {
        v[i]=v[i]*2/(double)n;
        s+=v[i];
    }
    cout<<fixed<<setprecision(10)<<s<<endl;
    return 0;
}