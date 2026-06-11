#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>//memset()
#include<algorithm>
#include<sstream>
#include<stack>
#include<bitset>
#include<queue>
#include<cmath>
#include<set>
#define ll long long
#define PI 3.14159265358979323846
#define IO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define rep(i,start,end) for(int i=start;i<end;i++)
#define per(i,start,end) for (int i=end-1;i>=start;i--)
using namespace std;

const ll mod=1000000007;
const ll inf=1e9;

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) { return a*b/gcd(a,b);}
ll leastbit(ll a) { return a&(-a);}
ll C(int a,int b) { ll res=1;rep(i,0,b)res=res*(a-i)/(i+1);return res;}
ll powmod(ll a,ll  b) { if(b==0)return 1;ll cnt=powmod(a,b/2);(cnt*=cnt) %=mod;if(b&1){(cnt*=a) %= mod;}return cnt;}

int n,m,k,a[200005],b[200005],idx=-1,ans=0;
ll sum=0;

int main()
{IO
#ifndef ONLINE_JUDGE
    freopen("output.txt","w",stdout);
#else
#endif
    
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    for(int i=0;i<n;i++){
        if(sum+a[i]<=k){
            idx=i;
            sum+=a[i];
        }
        else break;
    }
    ans=idx+1;int cnt=ans;
    for(int i=0;i<m;i++){
        while(sum+b[i]>k && idx>=0){
            sum-=a[idx];
            idx--;
            cnt--;
        }
        if(sum+b[i]<=k){
            cnt++;
            sum+=b[i];
        }
        else break;
        ans=max(cnt,ans);
    }
    cout<<ans<<endl;
    return 0;
}