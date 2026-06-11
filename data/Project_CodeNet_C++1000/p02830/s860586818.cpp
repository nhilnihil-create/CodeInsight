#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int N;
    string s, t;
    cin >> N;
    cin >> s >> t;
    string ans;
    ans = s+t;
    REP(i,2*N){
        if(i % 2 == 0){
            ans[i] = s[i/2];
        }
        else ans[i] = t[i/2];
    }
    cout << ans << endl;
}