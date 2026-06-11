#include <iostream>
#include <vector>
using namespace std;
const long long int MOD = 1000000007;

int main(){
    long long int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];

    long long int ans_in = 0;
    long long int ans_out = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(a[i] > a[j]){
                if(i < j) ans_in++;
                ans_out++;
            }
        }
    }

    long long int ans = 0;
    ans = ans_in * k;
    ans %= MOD;
    long long int c = k * (k-1);
    c /= 2LL;
    c %= MOD;
    ans += ans_out * c;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}