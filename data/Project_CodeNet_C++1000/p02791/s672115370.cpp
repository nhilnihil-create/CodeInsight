#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int N;
    cin >> N;
    int P[N];
    REP(i,N) cin >> P[i];
    int mi = N+1;
    int ans = 0;
    REP(i,N){
        if(P[i] <= mi){
            ans++;
            mi = P[i];
        }
    }
    cout << ans << endl;
}
