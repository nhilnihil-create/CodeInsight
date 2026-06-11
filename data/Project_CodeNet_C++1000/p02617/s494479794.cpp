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

int main(){
    int n;
    cin >> n;
    ll ans = 0;

    for(ll i = 1; i <= n; i++){
        ans += i*(n-i+1);
    }

    for(int i = 0; i < n-1; i++){
        ll a, b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        //ll node_num = a*(n-a+1)+b*(n-b+1);
        ll edge_num = a*(n-b+1);
        //ans += node_num;
        ans -= edge_num;
    }

    cout << ans << endl;
    
    return 0;
}