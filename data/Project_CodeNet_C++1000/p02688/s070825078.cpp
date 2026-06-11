#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,d;cin>>d>>t;
    set<int>s;
    while(t--)
    {
        int n;cin>>n;
        for(int i=0;i<n;i++)
        { int m;
            cin>>m;
            s.insert(m);
        }

    }
    cout<<d-s.size()<<endl;
}
