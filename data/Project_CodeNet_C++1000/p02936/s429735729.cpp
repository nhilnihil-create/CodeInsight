
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
#define PI 3.14159265359
#define dij priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
typedef long long ll;
//
vector<int> get_ans(int a,vector<vector<int>> tree,vector<int> vv){
    stack<pair<int,int>> st;
//    vector<int> ans(a);
    rep(i,tree[0].size()){
        st.push(make_pair(0,tree[0][i]));
    }
    vector<bool> flag(a,false);
    flag[0]=true;
    while(!st.empty()){
        auto p=st.top();st.pop();
        if(flag[p.S])continue;
        else{
        vv[p.S]+=vv[p.F]; 
        for(auto e:tree[p.S]){
            st.push(make_pair(p.S,e));
        }
        flag[p.S]=true;
        }
    }
    return vv;
}
int main(){
    int n,q;cin>>n>>q;
    vector<vector<int>> tree(n);
    rep(i,n-1){
        int a,b;cin>>a>>b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> vv(n,0);
    vector<pair<int,int>> v(q);
    rep(i,q){
        int a,b;cin>>a>>b;
        a--;
        v[i]=make_pair(a,b);
        vv[a]+=b;
    }
    vector<int> ans(n,0);
//    rep(i,q){
        ans=get_ans(n,tree,vv);
//        for(auto e:vvv)cout<<e;cout<<endl;
//    }
    for(auto e:ans)cout<<e<<" ";cout<<endl;
}
