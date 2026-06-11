#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int h[n]; for(int i = 0; i < n; ++i) cin >> h[i];
    int ans = 0, cnt = 0;
    for(int i = 1; i < n; ++i){
        if(h[i] <= h[i-1]) cnt++;
        else{
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    cout << ans << endl;
    return 0;
}