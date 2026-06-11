#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t,n;
    cin>>n>>t;
    vector<int>v(t);
    long long cnt=0;
    for(int i=0;i<t;i++)
    {
        cin>>v[i];
        cnt+=v[i];
    }
    if(cnt>=n)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
