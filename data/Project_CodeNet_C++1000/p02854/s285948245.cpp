#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
using Graph = vector<vector<int>>;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    ll ans = 0, half = 0;
    for(int i=0;i<n;i++){
        if(half <= sum/2 && sum/2 + 1 <= half + a[i]){
            ans = sum-half-half;
            if(i != 0) ans = min(ans, half+a[i] - (sum-(half+a[i])));
            break;
        }
        else half += a[i];
    }

    cout<<ans<<endl;
}