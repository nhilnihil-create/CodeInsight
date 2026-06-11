#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, x = 0;
    string s;
    char c;
    cin>>n>>s;
    x = s.size();
    c = s[0];
    for(ll i=1; i<s.size(); i++)
    {
        if(c == s[i])
        {
            x--;
        }
        else c = s[i];
    }
    cout<<x<<endl;
    return 0;
}
