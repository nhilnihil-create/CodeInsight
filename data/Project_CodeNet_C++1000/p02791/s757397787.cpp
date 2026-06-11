#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int mx = 2e9, ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x <= mx){
            ans++;
            mx = x;
        }
    }
    cout << ans;

    return 0;
}
