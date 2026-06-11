#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 100000007;
using Graph = vector<vector<int>>;

int main(){
    ll N;
    ll A,B;
    cin >> N >> A >> B;
    ll once = A+B;
    ll ans = 0;
    if(N%once==0){
        ll t = N/once;
        ans += A*t;
    }
    else{
        ll t = N/once;
        ans += A*t;
        ll re = N - t*once;
        if(A>re) ans += re;
        else ans += A;
    }
    cout << ans << endl;
}