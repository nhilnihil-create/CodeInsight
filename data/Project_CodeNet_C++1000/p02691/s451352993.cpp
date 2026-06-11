#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i,n)cin >> a[i];
    ll ans = 0;
    map<int,int>data;
    rep(i,n){
        int sa = i - a[i];
        ans += data[sa];
        int wa = i+a[i];
        data[wa]++;
    }
    cout << ans << endl;
    return 0;
}