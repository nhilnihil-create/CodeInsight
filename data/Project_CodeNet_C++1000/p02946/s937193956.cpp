#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int main()
{
    fastio;
    int n,k,i;
    cin>>n>>k;
    for (i=k-n+1;i<k;i++)
        cout<<i<<" ";
    for ( ;i<n+k;i++)
        cout<<i<<" ";
    cout<<endl;
}