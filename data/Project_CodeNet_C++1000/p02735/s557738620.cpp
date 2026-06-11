#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define mt make_tuple
#define pq priority_queue<ll>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vecpll vector<pll>
#define vecbl vector<bool>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
string stin(){string s;cin>>s;return s;}


int main(){
    int h=in(),w=in();
    vector<vec> a(h,vec(w));
    rep(i,h){
        string s=stin();
        rep(j,w){
            a[i][j]=s[j]=='.'?0:1;
        }
    }
    vector<vector<bool>> done(h,vector<bool>(w));
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> que;
    if(a[0][0]==0)que.push(mp(0,mp(0,0)));
    else que.push(mp(1,mp(0,0)));
    done[0][0]=true;
    while(!que.empty()){
        int cost = que.top().first,x=que.top().second.first,y=que.top().second.second;
        que.pop();
        if(x==h-1 && y==w-1){
            if(a[h-1][w-1]==1)cost++;
            cout<<cost/2<<endl;
            return 0;
        }
        if(x<h-1 && !done[x+1][y]){
            int new_cost=a[x][y]==a[x+1][y]?cost:cost+1;
            que.push(mp(new_cost,mp(x+1,y)));
            done[x+1][y]=true;
        }
        if(y<w-1 && !done[x][y+1]){
            int new_cost=a[x][y]==a[x][y+1]?cost:cost+1;
            que.push(mp(new_cost,mp(x,y+1)));
            done[x][y+1]=true;
        }
    }
}

