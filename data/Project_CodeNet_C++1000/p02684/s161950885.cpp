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
    ll n,k,loop=0;
    ll A[200005];
    ll log[200005];
    bool C[200005];
    cin>>n>>k;
    REP(i,n){
        C[i]=false;
        cin>>A[i];
    }
    log[0]=0;
    while(C[log[loop]]==false){
        C[log[loop]]=true;
        loop++;
        log[loop]=A[log[loop-1]]-1;
    }
    int x=log[loop],z=loop;
    int p=0;
    while(log[p]!=x&&k>0){
        p++;
        z--;
        k--;
    }
    //REP(i,loop+1) cout<<log[i]<<" ";
    //cout<<endl;
    //cout<<"z: "<<z<<endl;
    cout<<log[k%z+p]+1<<endl;
}