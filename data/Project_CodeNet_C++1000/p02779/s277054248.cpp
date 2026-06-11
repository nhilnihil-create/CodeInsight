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
    vector<int> A(N);
    REP(i,N) cin >> A[i];
    sort(A.begin(),A.end());
    bool ans = true;
    REP(i,N-1) if(A[i]==A[i+1]) ans = false;
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}