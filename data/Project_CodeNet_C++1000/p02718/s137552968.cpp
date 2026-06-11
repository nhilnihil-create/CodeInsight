#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,alla=0;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        alla+=a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    if(a[m-1]*(4*m)<alla) cout<<"No";
    else cout<<"Yes";
}