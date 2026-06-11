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
    vector<int> x(N);
    REP(i,N) cin >> x[i];
    sort(x.begin(),x.end());
    int ans = 1000000;
    int mi = x.at(0);
    int ma = x.at(N-1);
    for(int i = mi;i<=ma;++i){
        int s = 0;
        REP(j,N){
            int d = x[j]-i;
            d*=d;
            s+=d;
        }
        ans = min(ans,s);
    }
    cout << ans << endl;
}