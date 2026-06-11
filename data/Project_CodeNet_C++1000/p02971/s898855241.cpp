#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}


int main() {
    int n; cin >> n; int first = 0,second = 0;vector<int> v,z;v.assign(n,0);z.assign(n,0);
    for(int i = 0;i < n;i++){
        cin >> v[i]; z[i] = v[i];
    }
    sort(z.begin(),z.end(),greater<int>());first = z[0]; second = z[1];
    for(auto x:v) first > x ? cout << first << endl: cout << second << endl;
}
