#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;cin>>n;

    int a[n+1];

    memset (a , 0 , sizeof a);

    for(int i=0;i<n-1;i++)
    {
        int tmp;cin>>tmp;
        a[tmp]++;
    }

    for(int i=1;i<=n;i++)
     cout<<a[i]<<'\n';

}