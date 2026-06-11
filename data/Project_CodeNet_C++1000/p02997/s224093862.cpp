#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef int64_t Int;
using namespace std;


int main(){
    int N, K; cin >> N >> K;

    if(K > (N-1)*(N-2)/2){
        cout << "-1" << endl;
        return 0;
    } 

    vector<pair<int,int>> edge;
    rep(i, N-1) edge.push_back(make_pair(1, i+2));

    int from = 2, to = 3;
    rep(i, (N-1)*(N-2)/2 - K){
        if(to == N+1) {from++; to = from+1;}

        edge.push_back(make_pair(from, to));
        to++;
    }   

    cout << edge.size() << endl;
    rep(i, edge.size()){
        cout << edge[i].first << " " << edge[i].second << endl;
    }
}