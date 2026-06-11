#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
    int n; cin >> n;
    vector<int> honest(n, 0), unkind(n, 0);
    int ai, xij, yij;
    rep(i, n){
        cin >> ai;
        rep(j, ai){
            cin >> xij >> yij;
            if(yij) honest[i] |= (1<<(xij-1));
            else unkind[i] |= (1<<(xij-1));
        }
    }

    int ans = 0, cnt;
    bool isOk = true;
    rep(b, 1<<n){
        rep(i, n){
            if(!(b & (1<<i))) continue;
            
            if((b & unkind[i]) || ((~b) & honest[i])){
                isOk = false;
                break;
            }
        }

        if(isOk){
            cnt = bitset<16>(b).count();
            ans = max(ans, cnt);
        }
        isOk = true;
    }

    cout << ans << endl;
    return 0;
}