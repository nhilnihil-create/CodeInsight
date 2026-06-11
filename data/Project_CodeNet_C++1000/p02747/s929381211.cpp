#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    if(s.size()%2==1)
    {
        cout<<"No";
        return 0;
    }
    for(int i=0;i+1<s.size();i+=2)
        if(s[i]!='h'||s[i+1]!='i')
    {
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
    return 0;
}
