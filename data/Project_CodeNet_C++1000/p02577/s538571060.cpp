#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mod=1e9+7;
const int N=1e6+10;
void read(int &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0') if(ch=='-') d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
void read(ll &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0') if(ch=='-') d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
int main()
{
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();i++)
        sum+=s[i]^48;
    if(sum%9==0) puts("Yes");
    else puts("No");
    return 0;
}
