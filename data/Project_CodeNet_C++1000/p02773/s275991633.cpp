#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int main(){
    int N;
    cin >> N;
    string S[N];
    REP(i,N) cin >> S[i];
    map<string,int> V;
    REP(i,N){
        if(V.count(S[i])) ++V[S[i]];
        else V[S[i]] = 1;
    }
    int ma = 0;
    for(auto x:V){
        int a = x.second;
        ma = max(ma,a);
    }
    for(auto x:V){
        int a = x.second;
        if(a==ma) cout << x.first << endl;
    }
}