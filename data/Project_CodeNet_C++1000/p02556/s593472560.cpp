#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int n;
    cin >> n;
    ll z[n],w[n];
    for(int i=0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        z[i]=x+y;
        w[i]=x-y;
    }

    //cout << 2*M << endl;

    ll zmax=INT64_MIN,wmax=INT64_MIN,wmin=INT64_MAX,zmin=INT64_MAX;
    for(int i=0;i<n;i++){
        zmax=max(zmax,z[i]);
        zmin=min(zmin,z[i]);
        wmax=max(wmax,w[i]);
        wmin=min(wmin,w[i]);
    }

    ll ans=max(zmax-zmin,wmax-wmin);
    cout << ans << endl;
}