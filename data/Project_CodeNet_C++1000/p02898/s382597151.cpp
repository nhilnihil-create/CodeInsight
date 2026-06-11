#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, k; cin >> n >> k;
    int count = 0;
    rep(i, n){
        int a; cin >> a;
        if(a >= k) count++;
    }
    cout << count << endl;
    return 0;
}
