#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
ll power(ll a,ll x){
    ll res=1;
    while(x>0){
        if(x&1) res=res*a%2019;
        a=a*a%2019;
        x>>=1;
    }
    return res;
}
int main(){
    string s;cin>>s;
    int n=(int)s.size();
    vector<ll> dp(n+1,0),cnt(2019,0);
    for(int i=0;i<n;i++){
        dp[i+1]=(dp[i]+(ll)(s[n-1-i]-'0')*power(10,i))%2019;
        cnt[dp[i+1]]++;
    }
    cnt[0]++;
    ll ans=0;
    for(int i=0;i<2019;i++){
        ans+=cnt[i]*(cnt[i]-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}