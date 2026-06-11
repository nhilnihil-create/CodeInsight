#include <bits/stdc++.h>
using namespace std;

bool check(long long N, long long M, vector<long long> s, vector<long long> c, string str){
    if(str.size() != N) return false;
    for(long long i = 0; i < M; ++i){
        if(str[s[i]] != (char)(c[i] + '0')) return false;
    }
    return true;
}

void solve(long long N, long long M, std::vector<long long> s, std::vector<long long> c){
    for(int i = 0; i <= 999; ++i){
        string str = to_string(i);
        if(check(N, M, s, c, str)){
            cout << str << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> s(M);
    std::vector<long long> c(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&s[i]);
        s[i]--;
        scanf("%lld",&c[i]);
    }
    solve(N, M, std::move(s), std::move(c));
    return 0;
}
