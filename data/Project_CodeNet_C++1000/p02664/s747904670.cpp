#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    getline(cin,s);
    ll len=s.size();
    ll i,flag=0;
    for(i=0; i<len; i++)
    {
        if(s[i]=='?')
        {
            s[i]='D';
        }
    }

    cout<<s<<endl;

    return 0;
}
