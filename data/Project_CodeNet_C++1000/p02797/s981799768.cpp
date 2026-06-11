#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    int n,k,s;
    cin >> n >> k >> s;
    REP(i,k){
        cout << s;
        if(i!=n-1)cout << " ";
    }
    REP(i,n-k){
        if(s!=INF)cout << INF;
        else cout << 1;
        if(i!=(n-k-1))cout << " ";
    }
    cout << endl;
    return 0;
}