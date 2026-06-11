#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
int main(){
    ll a[4],result=-1000000000000000000LL;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    result = max(result,a[0]*a[2]);
    result = max(result,a[0]*a[3]);
    result = max(result,a[1]*a[2]);
    result = max(result,a[1]*a[3]);
    cout << result << endl;
}
