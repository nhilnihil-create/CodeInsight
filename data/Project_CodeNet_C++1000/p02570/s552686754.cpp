#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d,t,s;
    cin>>d>>t>>s;
    float ans=1.0*d/s;
    int k=ceil(ans);
    if(k<=t) cout<<"Yes";
    else cout<<"No";    
    return 0;
}