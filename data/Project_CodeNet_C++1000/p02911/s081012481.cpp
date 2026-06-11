#include <bits/stdc++.h>
using namespace std;

int m[100010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k,q;
    cin>>n>>k>>q;

    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;

        m[a-1]++;
    }

    for(int i=0;i<n;i++)
    {
        cout<<(k-q+m[i]>0?"Yes":"No")<<"\n";
    }

    return 0;
}
