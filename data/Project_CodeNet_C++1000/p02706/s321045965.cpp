#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int s=0;
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        s+=a;
    }
    if(n<s) cout << "-1" << "\n";
    else cout << n-s << "\n";

    return 0;
}