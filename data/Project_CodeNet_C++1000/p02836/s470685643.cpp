#include <bits/stdc++.h>
using namespace std;


void solve(std::string S){
    int cnt = 0;
    int N = S.size();
    for(int i = 0; i < N/2; ++i){
        //cout << S[i] << " " << S[N-1-i] << endl;
        if(S[i] != S[N-1-i]) cnt++;
    }
    cout << cnt << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
