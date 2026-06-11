#include <bits/stdc++.h>
#include <list>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 100000007;
using Graph = vector<vector<int>>;


int main(){
    string S;
    cin >> S;
    int N = S.size();
    bool p = true;
    REP(i,N/2) if(S[i]!=S[N-i-1]) p = false;
    REP(i,N/4) if(S[i]!=S[N/2-i-1]) p = false;
    for(int i = N/2 + 1; i < N; ++i){
        if(S[i]!=S[N-i-1]) p = false;
    } 
    if(p) cout << "Yes" << endl;
    else cout << "No" << endl;
}