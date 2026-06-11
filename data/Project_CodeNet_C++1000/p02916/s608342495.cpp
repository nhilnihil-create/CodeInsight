#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c=0;
    vector<int> v1(n+1),v2(n+1),v3(n);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v1[i];
    for(int i=1;i<=n;i++)
        cin>>v2[i];
        for(int i=1;i<n;i++)
        cin>>v3[i];
    for(int i=1;i<=n;i++)
    {
        c+=v2[v1[i]];
        if(v1[i]==1+v1[i-1])
        {
            c+=v3[v1[i-1]];

        }

            //cout<<c<<endl;
    }
    cout<<c<<endl;
}
