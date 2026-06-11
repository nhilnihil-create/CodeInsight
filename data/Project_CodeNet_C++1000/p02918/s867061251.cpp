//https://atcoder.jp/contests/agc038/tasks/agc038_a
#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
using namespace std;
int main()
{
    int n,k;string s;
    cin>>n>>k;cin>>s;
    int ans=0;
    for(int i=1;i<n;i++) if(s[i]==s[i-1]) ans++;
    cout<<min(ans+2*k,n-1);
    return 0;
}
