#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int main(){
    string S,T;
    int A,B;
    string U;
    cin >> S >> T >> A >> B >> U;
    if(S==U) cout << --A << " " << B << endl;
    else cout << A << " " << --B << endl;
}