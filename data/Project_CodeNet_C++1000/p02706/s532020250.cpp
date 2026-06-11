#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    int sum=0;

    for(int i=0;i<m;i++)
    {
        int tmp;cin>>tmp;
        sum+=tmp;
    }

    if(n-sum<0)
    {
        cout<<-1<<'\n';
        return 0;
    }

    cout<< n-sum<<'\n';
}