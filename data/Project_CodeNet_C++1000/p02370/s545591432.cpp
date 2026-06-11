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
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define INF 10e16
#define MOD 1000000007
#define  mod 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
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
vector<int>G[100001];
list<int> out;
bool V[100001];
int N;
int indeg[100001];

void bfs(int s){
    queue<int>q;
    q.push(s);
    V[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        out.pb(u);
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            indeg[v]--;
            if(indeg[v]==0&&!V[v]){
                V[v]=1;
                q.push(v);
            }
        }
    }
}

void tsort(){
    for(int i=0;i<N;i++){
        indeg[i]=0;
    }
    for(int u=0;u<N;u++){
        for(int i=0;i<G[u].size();i++){
            indeg[G[u][i]]++;
        }
    }
    for(int u=0;u<N;u++){
        if(indeg[u]==0&&!V[u])bfs(u);
    }
    for(list<int>::iterator it=out.begin();it!=out.end();it++){
        cout<<*it<<endl;
    }
}
//---------------------------------------------------------------------------
int main(){//問題をちゃんと見ろ!!!!!!!!!!!!!!!!!      llか??????????        memset()!!!!!!!!!!!!       ペナを減らせ!!!!!!!!!!!!!
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    int s,t,M;
    cin>>N>>M;
    for(int i=0;i<N;i++)V[i]=0;
    for(int i=0;i<M;i++){
        cin>>s>>t;
        G[s].pb(t);
    }
    tsort();
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------





