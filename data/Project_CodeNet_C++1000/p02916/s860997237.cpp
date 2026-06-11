#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n - 1);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        ans += b[i];
    }
    for(int i = 0; i + 1 < n; i++){
        cin >> c[i];
    }
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1] + 1){
            ans += c[a[i] - 2];
        }
    }
    cout << ans;

    return 0;
}

