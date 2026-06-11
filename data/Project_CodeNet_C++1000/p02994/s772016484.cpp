#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    rep(i,n) a[i] = l+i;
    int sum = 0;
    rep(i,n) sum += a[i];
    int ans = -1;
    int d = 1e9;
    rep(i,n){
        int x = sum - a[i];
        d = min(d, abs(sum-x));
        if(d == abs(x-sum)) ans = x;
    }
    cout << ans << endl;
}