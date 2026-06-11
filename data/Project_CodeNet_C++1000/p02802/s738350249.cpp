#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    long long n,m,p,i,r=0,t=0;
    map<long long,long long>ac,wa;
    string s;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>p>>s;
        if(s=="AC")
        {
            ac[p]++;
            if(ac[p]==1)
            {
                r++;
                t+=wa[p];
            }
        }
        else 
        {
            wa[p]++;
        }
    }
    cout<<r<<" "<<t<<endl;
    return 0;
}