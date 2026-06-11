#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
    int N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    A--, B--, C--, D--;
    bool ok = true;
    for(int i = A; i < C; i++){
        if(S[i] == S[i+1] && S[i] == '#') ok = false;
    }
    for(int i = B; i < D; i++){
        if(S[i] == S[i+1] && S[i] == '#') ok = false;
    }
    if(C > D){
        bool pass = false;
        for(int i = B-1; i < D; i++){
            if(S[i] == S[i+1] && S[i] == S[i+2] && S[i] == '.') pass = true;
        }
        if(pass == false) ok = false; 
    }
    
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}