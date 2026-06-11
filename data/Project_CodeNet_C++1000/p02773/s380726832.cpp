#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c=0,d,n,t,j,k,x,y,m,p,s,mx=0,mn;
    cin>>t;
    map<string,int>poll;
    vector<string>v;
    //string ar[t];
    for(p=0;p<t;p++)
    {
        string ss;
        cin>>ss;
        poll[ss]++;
    }
    map<string, int>::iterator it = poll.begin();
    for(it=poll.begin();it!=poll.end();it++)
    {
        c=max(c,it->second);
        //cout<<c<<endl;
    }
    int l=0;
    for(it=poll.begin();it!=poll.end();it++)
    {
        if(c==it->second)
        {
            v.push_back(it->first);
            l++;
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<l;i++)
    {
        cout<<v[i]<<endl;
    }
}
