#include <bits/stdc++.h>
using namespace std;
int n,x;
multiset <int, greater<int> > s;
multiset <int> v;
int main()
{
    cin>>n;
    for(int i=0;i<(1<<n);i++)
    {
        cin>>x;
        s.insert(x);
    }
    v.insert(*s.begin());
    s.erase(s.begin());
    for(int i=0;i<n;i++)
    {
        vector <int> add_v;
        for(multiset <int>:: iterator it=v.begin();it!=v.end();it++)
        {
            if(s.lower_bound(*it-1)==s.end())
            {
                cout<<"No";
                return 0;
            }
            add_v.push_back(*(s.lower_bound(*it-1)));
            s.erase(s.lower_bound(*it-1));
        }
        for(int j=0;j<(int)add_v.size();j++)
            v.insert(add_v[j]);
    }
    cout<<"Yes\n";
    return 0;
}