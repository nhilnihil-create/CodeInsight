#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n;cin >>n;
    vector<int> a(n);
    REP(i,n)cin >> a[i];
    int ans = a[0];
    FOR(i,1,n){
        ans ^= a[i];
    }
    REP(i,n){
        cout << (ans^a[i]);
        if(i!=n-1)cout << " ";
    }
    cout << endl;
}
