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

    pair<int, int> p[10];

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        p[i]=make_pair(x,y);
    }

    vector<vector<int>> sv;
    sv.push_back({1});

    for(int i=2;i<=n;i++)
    {
        vector<vector<int>> bsv=sv;
        sv.clear();
        for(auto b:bsv)for(int j=0;j<i;j++)
        {
            vector<int> s=b;
            s.push_back(0);
            for(int k=i;k>j;k--)s[k]=s[k-1];
            s[j]=i;

            sv.push_back(s);
        }
    }

    double ans=0;

    for(auto s:sv)for(int i=1;i<n;i++)
    {
        double xx=p[s[i]-1].first-p[s[i-1]-1].first;
        double yy=p[s[i]-1].second-p[s[i-1]-1].second;

        ans+=sqrt(xx*xx+yy*yy);
    }

    int num=1;
    for(int i=1;i<=n;i++)num*=i;

    ans/=num;

    printf("%.10lf",ans);

    return 0;
}
