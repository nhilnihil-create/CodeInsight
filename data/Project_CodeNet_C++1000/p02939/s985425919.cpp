#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=1e9+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll ans=s.length();
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]==s[i+1])
        {ans--;
        i+=2;}
    }
    cout<<ans<<endl;
    return 0;
}