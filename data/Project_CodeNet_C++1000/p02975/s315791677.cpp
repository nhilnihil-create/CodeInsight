#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    int N; cin >> N;
    //if(N % 3 != 0){cout << "No" << endl; return 0;}
    map<int, int> M; 
    for(int i = 0; i < N; i++) { int x; cin >> x; M[x]++;}
    set<int> ST; for(auto m : M) ST.insert(m.first);
    if(M.size() > 3){ cout << "No" << endl; return 0;}
    else if(M.size() == 2){
        bool flag = true;
        for(auto st : ST){
            if(st == 0 && M[st] == (N/3)) continue;
            else if(st != 0 && M[st] == 2*(N/3))continue;
            else flag = false;
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(M.size() == 1){
        if(M[0] == N) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        bool flag = true;
        for(auto m : M) if(m.second != N/3) flag = false;
        vector<ll> V; for(auto m : M) V.push_back(m.first);
        if((V[0]^V[1]) == V[2] && (V[1]^V[2]) == V[0] && (V[2]^V[0]) == V[1]) ;
        else flag = false;
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


}