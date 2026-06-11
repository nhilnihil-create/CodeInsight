#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<string,int>m;
    string u,s,t;
    lli a,b;
    cin>>s>>t;
    cin>>a>>b;
    m[s]+=a;
    m[t]+=b;
    cin>>u;
    m[u]--;
    cout<<m[s]<<" "<<m[t];
}