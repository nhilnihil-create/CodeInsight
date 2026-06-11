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
ll MOD=1e9+7;

ll power(ll a,ll x){
    ll res=1;
  while(x>0){
    if(x&1) res=res*a%13;
    a=a*a%13;
    x>>=1;
  }
    return res;
}

int main(){
    string s;cin>>s;
    int n=(int)s.size();
    vector<vector<ll> > dp(n+1,vector<ll>(13,0));
    dp[n][0]=1;
    for(int i=n;i>0;i--){
        for(int j=0;j<13;j++){
            if(s[i-1]=='?'){
                for(int d=0;d<10;d++){
                    dp[i-1][(d*power(10,n-i)+j)%13]+=dp[i][j];
                    dp[i-1][(d*power(10,n-i)+j)%13]%=MOD;
                }
            }else{
                int d=(int)(s[i-1]-'0');
                dp[i-1][(d*power(10,n-i)+j)%13]+=dp[i][j];
                dp[i-1][(d*power(10,n-i)+j)%13]%=MOD;
            }
        }
    }
    cout<<dp[0][5]<<endl;
    return 0;
}