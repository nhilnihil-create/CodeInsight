#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>=k)
            cnt++;
    }
    cout<<cnt<<'\n';




}
