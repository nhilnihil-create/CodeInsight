#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define what_is(x) cerr << #x << " = " << x << endl;
typedef long long ll;
int main()
{
    fastIO
    string s,t;

    cin>>s>>t;

    int ans=0;

    for (int i=0; i<s.size(); ++i)
    {
        ans+=(s[i]!=t[i]);
    }
    cout<<ans;
}
