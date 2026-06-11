#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int L = N&(-N);
    if(N == L){
        cout << "No" << endl;
        return 0;
    }

    vector<pair<int, int>> ans;
    int M = N - (N%2 == 0);
    for(int i=2; i<=M; i++){
        ans.emplace_back(1, i);
        ans.emplace_back(N+i, i^1);
    }
    ans.emplace_back(N+1, N+3);
    if(N%2 == 0){
        ans.emplace_back(N, N-L+1);
        ans.emplace_back(2*N, L);
    }

    cout << "Yes" << endl;
    for(auto& p : ans) cout << p.first << " " << p.second << endl;
    return 0;
}
