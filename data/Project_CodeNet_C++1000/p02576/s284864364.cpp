#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define ll long long
int main()
{
    faster();
    int t,n,x;
    cin>>n>>x>>t;
    int ans;
    if(n%x==0) ans = n/x;
    else ans = n/x + 1;
    cout<<ans*t<<endl;

    return 0;
}

