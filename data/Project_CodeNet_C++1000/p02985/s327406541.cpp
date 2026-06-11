//  Created by conan1024hao in 2019.
//  Copyright © 2019 conan1024hao. All rights reserved.
//  専用ライブラリです、自由にコピーして構いません。
//  感谢看我的代码！Wechat:conan1024hao QQ:810396815
#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 10e8
#define INF 10e16
#define MOD 1000000007
#define mod 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
using namespace std;
//using Int=int_fast64_t;
typedef long long int ll;
typedef pair<ll,ll>Pll;
typedef pair<int,int>Pin;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};
char dir[4]={'u','l','d','r'};
ll cmp1(pair<ll,string>a,pair<ll,string> b){
        if(a.fi!=b.fi)
        return a.fi<b.fi;
        else
        return a.se<b.se;
}
//--------------------------------------------------------------------------
int n,k;
vector<int>ab[100001];
ll used=2;
ll ans;
bool color[100001];
void dfs(int x){

    color[x]=1;
    bool abc=1;
    ll minus=0;
    //cout<<ans<<endl;
    for(int i=0;i<siz(ab[x]);i++){
        if(color[ab[x][i]])continue;
        if(x==0)used=1;
        else used=2;
        if(k-used-minus<0){
            ans=0;
        }
        ans*=(k-used-minus)%MOD;
        ans%=MOD;
        dfs(ab[x][i]);
        minus++;
        ans%=MOD;
        abc=0;
        
    }
    if(x==0)used=1;
    else used=2;
    
    ans%=MOD;
    
}
//---------------------------------------------------------------------------
int main(){//問題をちゃんと見ろ!!!!!!!!!!!!!!!!!      llか??????????        memset()!!!!!!!!!!!!       ペナを減らせ!!!!!!!!!!!!!
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    memset(color, 0, sizeof(color));
    cin>>n>>k;
    ans=k;

    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        ab[a].pb(b);
        ab[b].pb(a);
    }
    
    dfs(0);
    cout<<ans%MOD<<endl;
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------


