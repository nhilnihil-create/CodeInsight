//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n;
string s;
int mod=1e9+7;
int cache[100005][15];
int dp(int pos,int rem)
{
    if(pos==n)
        return rem==5;
    int &ans=cache[pos][rem];
    if(ans!=-1)
        return ans;
    ans=0;
    if(s[pos]!='?')
        return ans=dp(pos+1,(rem*10+s[pos]-'0')%13);
    else
    {
        for(int i=0;i<10;i++)
            ans+=dp(pos+1,(rem*10+i)%13);
        ans%=mod;
        return ans;
    }

}
int32_t main()
{
    IOS;
    cin>>s;
    n=s.length();
    memset(cache,-1,sizeof(cache));
    print(dp(0,0));
}