#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i, n)   for(ll i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    vector<ll>dic(n+1);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j+=i){
            dic[j]++;
        }
    }
    ll ans = 0;
    rep(i, n+1) ans += i*dic[i];
    cout << ans << endl;
}
