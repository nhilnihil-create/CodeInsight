#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ss;
    int n,sum=0;
    cin>>n;
    vector<pair<string,int> >v;
    for(int i=0; i<n; i++)
    {
        int t;
        string s;
        cin>>s>>t;
        sum+=t;
        v.push_back(make_pair(s,t));
    }

    //cout<<sum<<endl;

    cin>>ss;

    for(int i=0;i<v.size();i++)
    {
        //cout<<v[i].second<<" ";
        //cout<<sum<<" ";
        if(v[i].first==ss)
        {
            sum-=v[i].second;
            break;
        }
        else
        {
            sum-=v[i].second;
        }
    }

    cout<<sum<<endl;

    return 0;
}
