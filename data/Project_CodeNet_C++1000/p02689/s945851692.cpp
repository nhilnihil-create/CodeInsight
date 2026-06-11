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
    ll n,m,a,b,ans=0;
    bool C[100005];
    ll H[100005];
    vi K[100005];
    cin>>n>>m;
    REP(i,n) C[i]=true;
    REP(i,n) cin>>H[i];
    REP(i,m){
        cin>>a>>b;
        if(H[a-1]==H[b-1]) C[a-1]=C[b-1]=false;
        else if(H[a-1]>H[b-1]) C[b-1]=false;
        else C[a-1]=false;
    }
    REP(i,n) if(C[i]==true){
        ans++;
    } 
    cout<<ans<<endl;
}