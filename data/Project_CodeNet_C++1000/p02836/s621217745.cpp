#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    string S;
    cin >> S;
    int ans = 0;
    int x = S.size();
    REP(i,floor(x/2)){
        if(S[i] == S[x-i-1]) continue;
        else ans++;
    }
    cout << ans << endl;
}