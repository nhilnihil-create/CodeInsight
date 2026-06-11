#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j] << "   ";
		}
		cout << endl;
	}
}


int main(){//
    int N, Q;
    cin >> N >> Q;
    //vec[i][j]: 頂点iと結ばれている頂点の数列
    vector<vector<int>> vec(N, vector<int>());
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    //score[i]: 頂点iの点数
    vector<ll> score(N, 0);//とりあえず指定された頂点piのみにxiを足す．
    for(int i=0; i<Q; i++){
        int p, x;
        cin >> p >> x;
        p--;
        score[p] += x;
    }

    // cout << " vec: " << endl; print_vec2(vec);
    // cout << " score: " ; print_vec(score);

    //頂点iのカウンター値は iの親ノードのカウンター値と iのscoreの和
    vector<ll> ans(N, 0);//ans[i]: 頂点iのカウンター値
    // DFSする   ( BFSの解法は下にあるよ)
    //stack.first: 注目ノード,  second: 注目ノードの親
    stack<P> st;
    st.push(P(0, -1));
    while(st.size() != 0){
        int child = st.top().first;
        int parent = st.top().second;
        ans[child] += score[child];
        st.pop();

        for(int j=0; j<vec[child].size(); j++){
            int next_c = vec[child][j];
            if(next_c == parent) continue;
            ans[next_c] += ans[child];
            st.push(P(next_c, child));
        }
    }

    
    
    // //BFSする   ACしました!
    // //q.fist: 注目ノード, q.second: 注目ノードの親
    // queue<P> q;
    // q.push(P(0, -1));
    // while(q.size() != 0){
    //     int child = q.front().first;
    //     int parent = q.front().second;
    //     ans[child] += score[child];
    //     q.pop();
    //     for(int j=0; j<vec[child].size(); j++){
    //         int next_c = vec[child][j];
    //         // cout << " cihld: " << child << "  parent: " << parent << "  next_c: " << next_c << endl;
            
    //         if(next_c == parent) continue;
    //         ans[next_c] += ans[child];
    //         q.push(P(next_c, child));

    //     }
    // }

    for(int i=0; i<N; i++){
        cout << ans[i] << endl;
    }
    
}