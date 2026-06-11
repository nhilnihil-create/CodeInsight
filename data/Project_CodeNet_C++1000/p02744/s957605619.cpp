#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

ll N;

void solve_sub(ll max_char, const string& s){
    if(s.size() == N){
        cout << s << endl;
        return;
    }

    for(ll i = 0; i <= max_char + 1; ++i){
        char c = 'a' + static_cast<char>(i);
        solve_sub(max(max_char, i), s + c);
    }
}

int main(){
    cin >> N;
    solve_sub(-1, "");
    return 0;
}
