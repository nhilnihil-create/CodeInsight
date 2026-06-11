#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
#define lli                                 long long int
#define lb                                  long double
#define pi                                  acos(-1)
#define FindDistance(ax,ay,bx,by)           sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define gcd(a,b)                            __gcd(a,b)
#define lcm(a,b)                           (a/gcd(a,b))*b
#define T                                  int t;cin>>t;for(int tt=1;tt<=t;tt++)
#define all(v)                             v.begin(),v.end()
#define pb                                 push_back
#define inf                                999999999999999
#define mod                                1000000007
#define maxn                               100003
#define FastIO                             ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    lli n,i,x,j,ans;
    string s;
    map<string,lli>ma;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        ma[s]+=1;
    }
    ans=-1;
    //map<string,lli>:: iterator itr;
    for(auto itr=ma.begin();itr!=ma.end();itr++)
    {
        x=itr->second;
        if(x>ans)
            ans=x;
    }
    //map<string,lli>:: iterator itr;
    for(auto itr=ma.begin();itr!=ma.end();itr++)
    {
        if(itr->second==ans)
            cout<<itr->first<<endl;
    }


    return 0;
}
