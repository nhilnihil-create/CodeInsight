#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin>>s;
    int l=s.size();
    ll sum=0;
    for(int i=0;i<l;i++)
    {
        sum+=(s[i]-'0');
    }
    if(sum%9)
        cout<<"No";
    else
        cout<<"Yes";
}
