#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pc __builtin_popcountll

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    int ans = -1;
    ll val = 0;
    for(int i = 1; i <= k; ++i){
        val *= 10;
        val += 7;
        val %= k;
        if(val == 0){
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}