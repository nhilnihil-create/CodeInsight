#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    int n,m;
    cin>>n>>m;
    if(n>=m)
    {
        for(int i = 0;i<n;i++)cout<<m;
    }
    else
    {
        for(int i = 0;i<m;i++)cout<<n;
    }
    return 0;
}
