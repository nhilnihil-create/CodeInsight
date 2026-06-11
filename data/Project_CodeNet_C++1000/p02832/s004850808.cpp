#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int N;
    cin >> N;
    int A[N];
    REP(i,N) cin >> A[i];

    int count = 1;
    int ans = 0;
    REP(i,N){
        if(A[i] == count) count++;
    }
    if(count == 1) cout << -1 << endl;
    else cout << N-count+1 << endl;
}