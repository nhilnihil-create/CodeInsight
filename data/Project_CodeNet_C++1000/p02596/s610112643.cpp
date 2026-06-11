#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void){
    int K;
    cin >> K;

    int start = 7 % K;
    int mod_value = start;
    int ans = 1;
    for(int i=0;i<K;i++){
        if(mod_value == 0){
            cout << ans << endl;
            return 0;
        }
        mod_value = (mod_value*10+7) % K;
        if(mod_value == start){
            cout << -1 << endl;
            return 0;
        }
        ans++;
    }

    cout << -1 << endl;

    return 0;
}