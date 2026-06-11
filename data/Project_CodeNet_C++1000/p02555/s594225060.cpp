#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define maxx 1000001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    FASTIO
    int s;
    cin>>s;
    ll dp[s];
    dp[0]=1;dp[1]=dp[2]=0;
    for(int i=3;i<=s;i++)
        dp[i]=(dp[i-1]+dp[i-3])%mod;
    cout<<dp[s]%mod<<endl;
    return 0;
}
