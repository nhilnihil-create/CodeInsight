#include<bits/stdc++.h>
using namespace std;
#define p pair<int,int>
int N, K;
vector<p> n;

int main(){
    cin >> N >> K;
    for(int i = 2; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            n.push_back({i, j});
        }
    }
    int mx = (N - 1) * (N - 2) / 2;
    if(K > mx){
        cout << -1 << endl;
        return 0;
    }
    cout << N - 1 + mx - K << endl;
    for(int i = 2; i <= N; i++){
        cout << 1 << " " << i << endl;
    }
    for(int i = 0; i < mx - K; i++){
        cout << n[i].first << " " << n[i].second << endl;
    }
    return 0;
}