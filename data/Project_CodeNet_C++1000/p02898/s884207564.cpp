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
#define ld long double
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define piii pair<int,pii>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define FTEST int testcase;fin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
#define plll pair<ll,pll>
#define plii pair<ll,pii>
#define no {cout<<"no"<<endl;return;}
#define yes {cout<<"yes"<<endl;}
#define rep(i,N) for(int i=0;i<N;i++)
const int maxn=1e6;
const int mod=998244353;
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int n,q,k,c=0;
void solve(){
    cin>>n>>k;
    while(n--){
        cin>>q;
        if(q>=k) c++;
    }
    cout<<c;
}
int main(){
    IO
    //TEST
    solve();

    return(0);
}
/*
1
aabce
ace
*/
