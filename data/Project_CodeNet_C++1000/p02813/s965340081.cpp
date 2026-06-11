#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    vector<int> v(n),p(n),q(n);
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++)cin>>q[i];
    for(int i=0;i<n;i++)v[i]=i+1;

    int a=0,b=0;

    int pos=1;
    while(a==0||b==0)
    {
        if(a==0)
        {   
            int i=0;
            for(;i<n;i++)if(v[i]!=p[i])break;
            if(i==n)a=pos;
        }
        if(b==0)
        {   
            int i=0;
            for(;i<n;i++)if(v[i]!=q[i])break;
            if(i==n)b=pos;
        }

        pos++;
        next_permutation(v.begin(),v.end());
    }

    cout<<abs(a-b)<<"\n";

    return 0;
}
