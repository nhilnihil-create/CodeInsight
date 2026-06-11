#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    int N,M,S,C; cin >> N >> M;
    map<int,int>mp{};
    
    if(N == 1 && M == 0){ cout << 0 << endl; return 0; }
    for(int i=0;i<M;i++){
        cin >> S >> C;
        if(mp.count(S) == 0 || mp[S] == C){ mp[S] = C; }
        else{ cout << -1 << endl; return 0; }
    }
    
    for(int i=1;i<=N;i++){
        if(mp.count(i) == 0){
            if(i == 1) mp[i] = 1;
            else mp[i] = 0;
        }
    }
    
    if(mp[1] == 0 && N !=1) cout << -1 << endl;
    else { for(int i=1;i<=N;i++){cout << mp[i]; } cout <<endl;}

} 