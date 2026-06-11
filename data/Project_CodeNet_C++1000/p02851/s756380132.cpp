//小数点以下　cout << fixed << setprecision(10) << num << endl;
//桁数はlog10(mid)でやれ　log(mid)/log(10)はWA
//long*long<0で判定するな
//開区間と閉区間
//アルファベットが何番目かは x=s[i]-'a'
//bfsはmain()内で　rep(i,h)rep(j,w)rep(i,4)でバグ
//切り上げ：(a+(b-1))/b
//32bit以上は 1ull<<j
// map 初期値0 for(auto itr=mp.begin();itr!=mp.end();++itr) itr->fi itr->se で全探索
// for(auto u:mp) u.fi u.se も可能
//n個のgcd,lcmは一つずつみて更新していく
//大きな数を扱うときは素因数分解した形で持っておく
// (l/a[i]) = l*powmod(a[i],MOD-2)%MOD;
//auto itr=lower_bound(ALL(a),key) a[itr-a.begin()]
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    vector<int> sum(n);
    map<int,int> mp;
    map<int,int> mp2;
    if(k==1){
        cout << 0 << endl;
        return 0;
    }
    mp[0]++;
    ll ans=0;
    rep(i,n){
        cin >> a[i];
        if(i==0) sum[0]=a[0]%k;
        else{
            sum[i]=(sum[i-1]+a[i])%k;
            mp[(i-sum[i-1]+k)%k]++;
            if(i-k+1>=0) mp2[(i-k+1-sum[i-k]+k)%k]++;
        }
        int fin=(i+1-sum[i]+k)%k;
        ans+=mp[fin];
        if(i-k+1>=0)ans-=mp2[fin];
    }
    cout << ans << endl;
}
