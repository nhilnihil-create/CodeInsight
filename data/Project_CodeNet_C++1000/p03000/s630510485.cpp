#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int ans = 1,d = 0,i = 0;
    while(d+a[i] <= x){
        if(i == n) break;
        ans++;
        d += a[i];
        i++;
    }
    cout << ans << endl;
    return 0;
}