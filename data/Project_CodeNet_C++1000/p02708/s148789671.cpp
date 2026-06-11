#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
const int INFTY =2147483647;
int main(){
    ll n,k,s=0,m=0,ans=0;
    cin>>n>>k;
    FOR(i,1,k){
        s+=i-1;
        m+=n-i+1;
    }
    FOR(i,k,n+2){
        s+=i-1;
        m+=n-i+1;
        ans=(ans+(m-s)+1)%MOD;
    }
    cout<<ans<<endl;
}