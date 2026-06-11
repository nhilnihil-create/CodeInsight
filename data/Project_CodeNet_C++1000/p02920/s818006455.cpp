#include <bits/stdc++.h>

using namespace std;
int n,val;
multiset<int> m1,m2;
int main()
{
    cin>>n;
    for(int i=1;i<=(1<<n);i++)
    {
        cin>>val;
        m1.insert(val);
    }
    auto it=m1.end();
    it--;
    int nr=*it;
    m2.insert(nr);
    m1.erase(it);
    for(int i=1;i<=n;i++)
    {
        for(auto it=m2.begin();it!=m2.end();it++)
        {
            nr=*it;
            auto it2=m1.lower_bound(nr);
            if(it2==m1.begin())
            {
                cout<<"No";
                return 0;
            }
            it2--;
            int nr2=*it2;
            if(nr2>=nr)
            {
                cout<<"No";
                return 0;
            }
            m2.insert(nr2);
            m1.erase(it2);
        }
    }
    cout<<"Yes";
    return 0;
}
