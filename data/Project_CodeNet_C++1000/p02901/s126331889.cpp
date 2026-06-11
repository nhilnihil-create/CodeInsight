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
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
#define plll pair<ll,pll>
#define piii pair<int,pii>
const ll MAXN=5e5;
const ll mod=998244353;
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int N,M,a,b,c;
ll dp[4100];
int price[1010];
int locks[1010];
bool subset(int i,int j){
    if(j==i) return(true);
    if(j>i) return(false);
    while(j){
        if(i%2!=j%2) return(false);
        i/=2;
        j/=2;
    }
    return(true);
}
void solve(){
    for(int i=0;i<4100;i++)
        dp[i]=MAX;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>price[i]>>b;
        locks[i]=0;
        while(b--){
            cin>>c;
            locks[i]+=(1<<(c-1));
        }
    }
    /*
    for(int i=0;i<M;i++){
        cout<<price[i]<<" "<<locks[i]<<endl;
    }
    */
    dp[0]=0;
    for(int j=0;j<M;j++){
        ll now=locks[j];
        for(int i=0;i<(1<<N);i++){
            dp[i|locks[j]]=min(dp[i|locks[j]],dp[i]+price[j]);
        }

    }

    //for(int i=0;i<=(1<<N);i++) cout<<dp[i]<<" ";






    if(dp[(1<<N)-1]>=MAX) cout<<-1;
    else cout<<dp[(1<<N)-1];

    return;

}
int main(){
    IO
    //TEST
    solve();

    return(0);
}
