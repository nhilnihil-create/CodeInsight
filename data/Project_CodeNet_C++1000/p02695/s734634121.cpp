#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, Q;
vector<int> a, b, c, d;
set<int> score_list;

void dfs(vector<int> &A){
   
    if(A.size() == 0){ //Aが空のとき（最初）
        for(int i=1; i<=M; i++){
            A.push_back(i);
            dfs(A);
            A.pop_back();
        }
    }
    
    else if(A.size() < N){
        for(int i=A.back(); i<=M; i++){
            A.push_back(i);
            dfs(A);
            A.pop_back();
        }
    }
    
    else{ // A.size() == N
        int score = 0;
        for(int i=0; i<Q; i++){
            if(A.at(b.at(i) - 1) - A.at(a.at(i) - 1) == c.at(i)) score += d.at(i);
        }
        score_list.insert(score);
    }

}

int main(){
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    for(int i=0; i<Q; i++) cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);

    vector<int> A;
    dfs(A);
    cout << *score_list.rbegin() << endl;
}