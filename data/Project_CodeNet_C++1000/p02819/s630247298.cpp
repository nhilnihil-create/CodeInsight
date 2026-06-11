#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;

const int mx = 100003;

int main() {
    int x;
    cin >> x;
    int ans;
    vector<bool> isPrime(mx+1,true);
    for(int i = 2; i <= mx; ++i) {
        if(!isPrime[i]) continue;
        if(i >= x) {
            ans = i;
            break;
        }
        for(int j = i * 2; j <= mx; j += i) isPrime[j] = false;
    }
    cout << ans << endl;

    return 0;
}
