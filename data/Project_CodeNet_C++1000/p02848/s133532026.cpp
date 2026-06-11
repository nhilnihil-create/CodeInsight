#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
int main()
{
    ll n; cin>>n;
//ll SUN, MON, TUE, WED, THU, FRI, SAT;
string s;
cin>>s;
for(ll i=0;i<s.size();i++)
{
    s[i]=s[i]+n;
    if(s[i]>90)
    {
        s[i]=s[i]-26;
    }
    cout<<s[i];
}
cout<<endl;
}
