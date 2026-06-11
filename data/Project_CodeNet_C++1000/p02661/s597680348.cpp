#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n%2){
        cout << b[n/2]-a[n/2]+1 << "\n";
    }
    else{
        int ans = (b[n/2]+b[n/2-1])-(a[n/2]+a[n/2-1])+1;
        cout << ans << "\n";
    }
    return 0;
}