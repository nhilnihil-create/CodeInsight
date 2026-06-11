#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main()
{
    long long n,i,ma=INT_MIN,mi=INT_MIN,k,c=0;
    cin>>n;
    vector<long long>v;
    for(i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    ma=v[0];
    k=0;
    for(i=1;i<n;i++)
    {
        if(v[i]>ma)
        {
            ma=v[i];
            k=i;
        }
    }
    for(i=0;i<n;i++)
    {
        if(v[i]==ma)
        {
            c++;
        }
    }
    for(i=0;i<n;i++)
    {
        if(v[i]!=ma)
        {
            mi=max(mi,v[i]);
        }

    }
   if(c>1)
   {
       for(i=0;i<n;i++)
       {
           cout<<ma<<endl;
       }
   }
   else
   {
    for(i=0;i<n;i++)
    {
        if(v[i]==ma)
        {
            cout<<mi<<endl;
        }
        else
        {
            cout<<ma<<endl;
        }
    }
   }
    cout<<endl;
    return 0;
}
