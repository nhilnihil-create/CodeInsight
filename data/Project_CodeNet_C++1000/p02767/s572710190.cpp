#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n,i,an=0,j,s=0;
    cin>>n;
    int m[n];
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    int ma=m[0];
    int mi=m[0];
    for(i=1;i<n;i++)
    {
        ma=max(ma,m[i]);
        mi=min(mi,m[i]);
    }
    int p=(ma+mi)/2;
    an=INT_MAX;
    for(j=mi;j<=ma;j++)
    {
        s=0;
        for(i=0;i<n;i++)
        {
           s=s+(j-m[i])*(j-m[i]);

        }
        an=min(an,s);
    }
    cout<<an<<endl;
    return 0;
}
