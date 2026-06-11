#include<bits/stdc++.h>

using namespace std;

int root(int idx, vector<int> &parent){
    if(parent[idx] == idx) return idx;
    return parent[idx] = root(parent[idx], parent);
}

int main(void){
    int N, M;
    cin >> N >> M;
    vector<int> parent(N), s(N);
    for(int i = 0; i < N; i++){
        parent[i] = i;
        s[i] = 1;
    }
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        int ra = root(A, parent);
        int rb = root(B, parent);
        if(ra != rb){
            parent[rb] = ra;
            s[ra] += s[rb];
        }

    }
    // for(int i = 0; i < N; i++) cout << i << " " << root(i, parent) << endl;
    cout << *max_element(s.begin(), s.end()) << endl;
    return 0;
}
