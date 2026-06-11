#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ARRS int(3e5+600)
#define BARRS int(2e6+600)
#define MAX ((long long)(1e17+1))
#define MMAX ((long long)(1e9+10))
#define HS1 ((long long)(1000001329))
#define HS2 ((long long)(1000001531))
#define MOD ((long long)1000000007)
#define SQ 31622780
#define PI 3.14159265358979323846264338327950288419716939937510

vector<ll> v[ARRS];
vector<ll> pas;
ll fx[ARRS];
void go(ll x){
    fx[x]--;
    pas.pb(x);
    for(auto y:v[x]){
        fx[y]--;
        if(!fx[y])go(y);
    }
}


int main(){
   #ifdef KHOKHO
    freopen("in.in","r",stdin);
    freopen("out.out","w+",stdout);
   #endif //KHOKHO
    ll n,m,k,p;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>k>>p;
        v[k].pb(p);
        fx[p]++;
    }

    for(int i=0; i<n; i++){
        if(!fx[i])
            go(i);
    }

    for(auto x:pas){
        cout<<x<<" ";
    }

   return 0;
}