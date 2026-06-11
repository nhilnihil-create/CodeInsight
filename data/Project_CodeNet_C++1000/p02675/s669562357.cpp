#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(long long N){
    string t = to_string(N);
    int i = t.size()-1;
    string ans = "";
    if(t[i] == '2' || t[i] == '4' || t[i] == '5' || t[i] == '7' || t[i] == '9') ans = "hon";
    if(t[i] == '0' || t[i] == '1' || t[i] == '6' || t[i] == '8') ans = "pon";
    if(t[i] == '3') ans = "bon";
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
