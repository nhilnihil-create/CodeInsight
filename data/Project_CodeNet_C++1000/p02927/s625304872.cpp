#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int m,d;
    cin >> m >> d;
    ll ans = 0;
    for(int i = 1 ; i <= m; i++){
        for(int j = 1; j <= d; j++){
            if(j/10 > 0){
                if(((j/10)%10)*(j%10) == i && ((j/10)%10) > 1 && j%10 > 1) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}