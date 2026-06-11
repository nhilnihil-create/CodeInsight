#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    long long n,k,i,s=0,s1=0;
    cin>>n>>k;
    vector<int>v;
    for(i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }
    s=0;
    sort(v.begin(),v.end());
    if(k>=n)
    {
        cout<<"0"<<endl;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            s=s+v[i];
        }
        i=n-1;
        while(k--)
        {
            s1=s1+v[i];
            i--;
        }
        cout<<s-s1<<endl;
    }
    return 0;
}
