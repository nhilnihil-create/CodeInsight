#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n,k,c;
string ss;
int dp[2][200005]={};
int dp1[2][200005]={};
int32_t main() 
{
    IOS;
    cin>>n>>k>>c>>ss;
    set<int>s,s1;
    for(int i=0;i<n;i++)
    {
        if(ss[i]=='o')
        {
            s.insert(i);
            i+=c;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(ss[i]=='o')
        {
            s1.insert(i);
            i-=c;
        }
    }
    if(s.size()>k)
        return 0;
    for(auto i:s)
        if(s1.find(i)!=s1.end())
            print(i+1);
}   
