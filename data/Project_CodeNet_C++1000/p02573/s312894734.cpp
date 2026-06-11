#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=(n)-1;i>j-1;i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

struct friendfind{
    
    vector<lli> par;
    
    friendfind(lli n){
        lli i;
        rep(i,0,n){
            par.push_back(i);
        }
    }
    
    lli root(lli x){
        if(par[x]==x){
            return x;
        }
        else{
            return par[x]=root(par[x]);
        }
    }
    
    void unit(lli a, lli b){
        lli ax=root(a);
        lli bx=root(b);
        if(ax!=bx){
            par[ax]=bx;
        }
    }
    
    void answer(){
        lli i,a=0;
        map<lli,lli> mp;
        rep(i,0,par.size()){
            mp[root(i)]++;
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            a=max(a,itr->second);
        }
        cout<<a<<endl;
    }
    
};

int main(){
    lli n,m,a,b;
    lli i,j;
    cin>>n>>m;
    friendfind bro(n);
    rep(i,0,m){
        cin>>a>>b;
        bro.unit(a-1,b-1);
    }
    bro.answer();
}
