#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

ll n,k;
ll mx = 0;
vector<ll> a(200001);

int search(int l, int r){
    int x = (l+r)/2;
    if(x == 0) return 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += a[i]/x -1;
        if(a[i]%x != 0) ans++;
    }

    if(ans > k){
        l = x;
    } else {
        r = x;
    }

    if(r-l <= 1) return r;
    else return search(l, r);
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int ans = search(0, mx);
    cout << ans << endl;

    return 0;
}