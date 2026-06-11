#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    string s;
    cin>>n>>s;
    ll gcd=0,r=0,g=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R') r++;
        if(s[i]=='G') g++;
        if(s[i]=='B') b++;
        for(int j=i+1,k=i+2;k<n;k+=2,j++)
            if((s[i]^s[j]^s[k])==('R'^'G'^'B')) gcd++;
    }
    cout<<(r*g*b)-gcd<<endl;
}
