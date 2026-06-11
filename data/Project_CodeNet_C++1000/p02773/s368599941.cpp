#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    map<str,int> m;

    for(int i=0;i<n;i++)
    {
        str s;
        cin>>s;

        m[s]++;
    }

    int ma=0;

    vector<str> ans;

    for(const auto& x : m)
    {
        if(ma<x.second)
        {
            ma=x.second;
            ans.clear();
            ans.push_back(x.first);
        }
        else if(ma==x.second)ans.push_back(x.first);
    }

    for(int i=0;i<ans.size();i++)cout<<ans[i]<<"\n";

    return 0;
}
