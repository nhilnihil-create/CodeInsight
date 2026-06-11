#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 10;
int a[N] , n;
unordered_map <int,int> mp;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        if (mp.count(i - a[i]) > 0) ans = ans + mp[i - a[i]]; // get result at [i]
        mp[a[i] + i]++; // update result at [i]
    }
    cout << ans;
    return 0;
}