/*
トポロジカルソートができる⇔DAG(閉路がない有向グラフ)である

vector<int>を引数にすることを前提にしている

O(V+E)

edgeなどを使う場合には、eの所をe.toにする必要がある
（逆に言えばそれだけでいい）
verify:
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
参考:
https://ferin-tech.hatenablog.com/entry/2017/01/24/184750
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
template<class T,class U>constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}
template<class T,class U>constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return true;}
using Graph=vector<vector<int>>;

//DAGではない場合、空のvectorを返す
template<typename G>
vector<int> TopologicalSort(G &v){
    int sz=(int)v.size();
    vector<int> cnt(sz,0);
    vector<int> ret;
    stack<int> st;
    for(int i=0;i<sz;i++){
        for(auto &e:v[i]){
            cnt[e]++;
        }
    }
    for(int i=0;i<sz;i++){
        if(cnt[i]==0) st.push(i);
    }
    while(!st.empty()){
        int now=st.top(); st.pop();
        ret.push_back(now);
        for(auto &e:v[now]){
            cnt[e]--;
            if(cnt[e]==0) st.push(e);
        }
    }
    if(ret.size()!=sz) return vector<int>();
    return ret; 
}

signed main(){
    int v,e;
    cin>>v>>e;
    Graph g(v);
    for(int i=0;i<e;i++){
        int s,t;
        cin>>s>>t;
        g[s].push_back(t);
    }
    vector<int> ret=TopologicalSort(g);
    for(auto i:ret){
        cout<<i<<endl;
    }
}
