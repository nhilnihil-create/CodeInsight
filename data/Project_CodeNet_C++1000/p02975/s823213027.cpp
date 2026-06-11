#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    bool allzero=true;

    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        m[a]++;
        if(a>0)allzero=false;
    }

    if(allzero)
    {
        cout<<"Yes"<<"\n";
        return 0;
    }

    if(n%3==0)
    {
        if(m.size()==3)
        {
            vector<int> v;
            vector<int> x;
            for(auto mm:m)
            {
                v.push_back(mm.second);
                x.push_back(mm.first);
            }

            if(v[0]==v[1]&&v[1]==v[2])
            {
                if((x[0]^x[1]^x[2])==0)
                {
                    cout<<"Yes"<<"\n";
                    return 0;
                }
            }
        }
        else if(m.size()==2)
        {
            bool zero=false;
            vector<int> v;
            for(auto mm:m)
            {
                v.push_back(mm.second);
                if(mm.first==0)zero=true;
            }

            if(zero)
            {
                if(v[0]*2==v[1]||v[1]*2==v[0])
                {
                    cout<<"Yes"<<"\n";
                    return 0;
                }
            }
        }
    }

    cout<<"No"<<"\n";

    return 0;
}