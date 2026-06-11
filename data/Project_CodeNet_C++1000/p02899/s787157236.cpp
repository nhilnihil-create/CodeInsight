#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        int ia;cin>>ia;
        a[i]=make_pair(ia,i+1);
    }

    sort(a.begin(),a.end());

    for(int i=0;i<n;i++)cout<<a[i].second<<" ";
    cout<<"\n";

    return 0;
}
