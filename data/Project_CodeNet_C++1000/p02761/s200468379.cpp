#include <bits/stdc++.h>
using namespace std;

vector<int> dignum(int X){
    if(X == 0) return {0};
    vector<int> res;
    while(X){
        res.push_back(X%10);
        X /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> S(M), C(M);
    for(int i=0; i<M; i++){
        cin >> S[i] >> C[i];
        S[i]--;
    }

    for(int x=0; x<1000; x++){
        auto v = dignum(x);
        if(v.size() != N) continue;
        bool ok = true;
        for(int i=0; i<M; i++) if(v[S[i]] != C[i]) ok = false;
        if(ok){
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
