#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int a,b;
    cin >> a >> b;
    int ans = 1;
    int total = a;
    if(b == 1){
        cout << 0 << endl;
        return 0;
    }
    while(total < b){
        total -= 1;
        total += a;
        ans++;
    }
    cout << ans << endl;
}