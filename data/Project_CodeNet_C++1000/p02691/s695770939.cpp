#include <bits/stdc++.h>
using namespace std;
map <long long ,int >m;
int main()
{
    int n;
    cin>>n;
    long long ans=0;
    for (int i=0;i<n;i++)
    {
        long long x=0;
        cin>>x;
        ans+=m[i-x];
       // cout<<i-x<<"    "<<m[i-x]<<endl;
         m[x+i]++;
    }
    cout<<ans<<endl;
    return 0;
}
