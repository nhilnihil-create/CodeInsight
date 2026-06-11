#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace __gnu_pbds;
using namespace std;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
*/
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
#define plll pair<ll,pll>
#define logg2 0.30102999566398119521373889472449L
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=2e5;
ll dp[maxn+1][13];
ll p=1;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    s=' '+s;

    memset(dp,0,sizeof dp);
    if(s[n]=='?'){
        for(int i=0;i<=9;i++) dp[n][i]++;
    }
    else dp[n][s[n]-'0']++;
    for(int i=n-1;i>=1;i--){
        p=(p*10)%13;
        if(s[i]!='?') {
            int k=s[i]-'0';
            for(int j=0;j<=12;j++){
                dp[i][(j+k*p)%13]=(dp[i][(j+k*p)%13]+dp[i+1][j])%MAX;
            }
        }
        else{
            for(int k=0;k<=9;k++){
                for(int j=0;j<=12;j++){
                    dp[i][(j+k*p)%13]=(dp[i][(j+k*p)%13]+dp[i+1][j])%MAX;
                }
            }
        }
    }
    cout<<dp[1][5];
    return;
}
int main(){
    IO
    //TEST
    solve();
    return(0);
}
