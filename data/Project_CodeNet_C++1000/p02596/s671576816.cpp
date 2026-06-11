#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    int k;
    cin >> k;
    int x = 7 % k;
    set<int> s;
    int ans = 1;
    while(s.count(x) == 0){
        if(x == 0){
            cout << ans << endl;
            return 0;
        }
        s.insert(x);
        x = (x * 10 + 7) % k;
        ans++;
    }
    cout << -1 << endl;
    return 0;
}