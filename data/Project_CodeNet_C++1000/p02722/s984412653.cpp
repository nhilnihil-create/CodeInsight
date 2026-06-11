#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
#define INF 100000000
#define MAX 200001
#define MOD 1000000009
ll fac[MAX],finv[MAX],inv[MAX];
typedef vector<vector<int> > Graph;
const int m=2019;

vector<ll> func(ll n){
    vector<ll> res;
    for(ll i=1;i*i<=n;i++){
        if(n%i!=0) continue;
        res.push_back(i);
        if(i*i!=n) res.push_back(n/i);
    }
    return res;
}

int main(){
    ll n;cin>>n;
    int ans=0;
    for(ll x : func(n)){
        if(x==1) continue;
        ll tmp=n;
        while(tmp%x==0) tmp/=x;
        tmp%=x;
        if(tmp==1) ans++;
    }
    ans+=func(n-1).size()-1;
    cout<<ans<<endl;
    return 0;
}