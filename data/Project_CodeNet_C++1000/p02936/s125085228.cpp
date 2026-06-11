#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int N, Q;
    cin>>N>>Q;

    vec_int a(N-1), b(N-1);
    rep(i,N-1)cin>>a.at(i)>>b.at(i);
    vec_int p(Q), x(Q);
    rep(i,Q)cin>>p.at(i)>>x.at(i);

    vec_int scores(N+1,0);
    rep(i,Q){
        scores.at(p.at(i)) += x.at(i);
    }

    vector<vector<int>> tree_str(N+1);
    for(int i=0;i<N-1;i++){
        tree_str.at(a.at(i)).push_back(b.at(i));
        tree_str.at(b.at(i)).push_back(a.at(i));
    }


    //深さ優先探索をする 幅優先探索でもOK
    // stackを使おう
    queue<P> next_nodes;
    vec_int visited(N+1,0);
    for(auto pos: tree_str.at(1)){
        next_nodes.push(make_pair(pos, scores.at(1)));
    }
    visited.at(1) = 1;

    while(next_nodes.size()>0){
        int pos, score; tie(pos,score) = next_nodes.front(); next_nodes.pop();
        visited.at(pos) = 1;
        scores.at(pos) = scores.at(pos) + score;

        for(auto next_pos: tree_str.at(pos)){
            if(visited.at(next_pos)==1)continue;
            next_nodes.push(make_pair(next_pos, scores.at(pos)));
        }
    }
    for(int i=1;i<N;i++){
        cout<<scores.at(i)<<" ";
    }
        cout<<scores.at(N)<<endl;

















    return 0;
}