#include<bits/stdc++.h>
#define ull unsigned long long
# define ll long long
# define mod 1000000007LL 
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]+n<='Z')
        {
            s[i]=s[i]+n;
           cout<<s[i];
        }
        else
        {
            ll temp=n-('Z'-s[i]+1);
            s[i]='A'+temp;
            cout<<s[i];
        }
        
    }


    
    return 0;
}