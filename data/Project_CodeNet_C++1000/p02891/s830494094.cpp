/*
 * @Author: RBQRBQ
 * @Date: 2020-04-09 19:07:43
 * @LastEditors: RBQRBQ
 * @LastEditTime: 2020-04-09 19:51:50
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;
namespace IO{
    template<typename T>inline void read(T &x){
        x=0;ll f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
        while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
        x=x*f;
    }
}
using namespace IO;
const int maxn=200;
ll K;
string s,p;
ll q(string s)
{
    int len=s.length();
    vector<ll> ans;
    ans.clear();
    int now=s[0];
    int res=1;
    for(int i=1;i<len;i++)
    {
        if(s[i]==now) res++;
        else
        {
            now=s[i];
            ans.push_back(res);
            res=1;
        }
    }
    ans.push_back(res);
    ll sum=0;
    for(auto p:ans)
    {
        sum+=(p/2);
    }
    return sum;
}
int main()
{
    cin>>s;
    read(K);
    p=s+s;
    bool ok=true;
    for(int i=0;i<s.length();i++)
    if(s[i]!=s[0]) ok=false;
    if(ok)
    {
        cout<<(K*s.length())/2;
        return 0;
    }
    ll sum1=q(s);
    ll sum2=q(p);
    ll pos=sum1*2-sum2;
    cout<<sum1*K-pos*(K-1);
}
