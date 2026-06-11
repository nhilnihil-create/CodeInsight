#include <bits/stdc++.h>
using namespace std;



int main() {
    int N,M;
    cin >> N >> M;
    vector<vector <int>> number(N,vector<int>(0));
    vector<bool> seen(N,false);
    vector<int> A(M);
    vector<int> B(M);

    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i];
    }

    for(int i = 0; i < M; i++){
        number[A[i]-1].push_back(B[i]-1);
        number[B[i]-1].push_back(A[i]-1);
    }

int ans = 0;
queue<int> stack;


    for(int i = 0; i < N; i++){
        int count = 0;
            if(seen[i]) continue;
            seen[i] = true;
            stack.push(i);
            while(!stack.empty()){
                int now = stack.front(); stack.pop();
                for(auto nv : number[now]){
                    if(!seen[nv]){
                    seen[nv] = true;
                    stack.push(nv);
                    }
            }
            count ++;
        }
    ans = max(ans,count);
    }

cout << ans << endl;

}
