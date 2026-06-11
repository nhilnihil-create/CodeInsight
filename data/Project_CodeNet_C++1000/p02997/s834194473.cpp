#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define all(ppp) ppp.begin(),ppp.end()
#define out(ppp) cout<<(ppp)<<endl
#define out1(ppp) cout<<(ppp) 
#define MAX_CHAR 256

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define pb push_back

typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<vpi> vvpi;

typedef set<pi> spi;

const int INF=INT_MAX;
void swap(ll &a,ll &b){
    ll temp=a;
    a=b;
    b=temp;
}
ll gcd(ll a,ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

ll lcm(ll a,ll b){
    ll ans=(a*b)/gcd(a,b);
    return ans;
}

void solve(){
    int N;
    int K;
    cin>>N>>K;
    vpi e1,e2;
    FOR(i,2,N+1){
        e1.emplace_back(1,i);
    }
    for(int i=2;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            e2.emplace_back(i,j);
        }
    }
    if(K>e2.size()){
        out(-1);
        return;
    }
    for(int i=0;i<K;i++){
        e2.pop_back();
    }
    out(e1.size()+e2.size());
    for(int i=0;i<e1.size();i++){
        cout<<e1[i].first<<" "<<e1[i].second<<endl;
    }
    for(int i=0;i<e2.size();i++){
        cout<<e2[i].first<<" "<<e2[i].second<<endl;
    }
    return;


}

int main(){
    solve();
    return 0;
}