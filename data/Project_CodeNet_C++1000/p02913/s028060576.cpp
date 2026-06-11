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
int store[5005];
string s;
int mul=41;
int mod=2016007997;
map<int,int>mp;
int check(int len)
{
    mp.clear();
    int mulpow=1;
    for(int i=0;i<len;i++)
        mulpow=(mulpow*mul)%mod;
    int val=0;
    for(int i=0;i<len;i++)
    {
        val=(val*mul+s[i])%mod;
        store[i]=val;
    }
    mp[val]=len-1;
    for(int i=len;i<n;i++)
    {
        val=(val*mul+s[i])%mod;
        store[i]=val;
        int get=(store[i]-((mulpow*store[i-len])%mod)+mod)%mod;
        if(!mp[get])
            mp[get]=i;
        else
        {
            if(i-mp[get]>=len && s[i]==s[mp[get]])
                return true;
        }
    }
    return false;
}
int32_t main() 
{
    IOS;
    cin>>n>>s;
    int low=0;
    int high=n/2;
    while(low<high)
    {
        int mid=(low+high+1)/2;
        if(!check(mid))
            high=mid-1;
        else
            low=mid;
    }
    print(low);
}