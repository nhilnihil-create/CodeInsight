#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i < n; i++) cin >> c[i];

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += b[a[i]];
        if(i-1 >= 0 && a[i-1]+1 == a[i]) ans += c[a[i-1]];
    }
    cout << ans << endl;
    return 0;
}