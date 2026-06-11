#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N,M;
    cin >> N >> M;
    vector<int64_t> A(N),B(N);
    for ( int64_t i = 0; i < N; ++i){
        cin >> A.at(i) >> B.at(i);
    }
    
    vector<vector<int64_t>> AB;
    AB.resize(M+1);
    // AB.at(i) i日後にもらえる仕事
    for ( int i = 0; i < N; ++i){
        if ( A.at(i) > M ) continue;
        AB.at(A.at(i)).push_back(B.at(i));
    }
    
    //cout << "A" << endl;
    
    priority_queue<int64_t> que;
    int64_t ans = 0;
    for (int d = 1; d <= M; ++d){
        for ( int i = 0; i < AB.at(d).size(); ++i){
            que.push(AB.at(d).at(i));
        }
        if ( que.size() ){
            ans += que.top(); que.pop();
        }
    }

    cout << ans << endl;
    
    
    return 0;
}