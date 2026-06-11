#include <iostream>
#include <string>
using namespace std;
int n;
long long  pprev;
long long  ans;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        long long val; cin >> val;
        if(pprev > val) ans+= pprev - val, val = pprev;
        pprev = val;
    }
    cout << ans << endl;
}