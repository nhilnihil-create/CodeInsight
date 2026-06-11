#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    if(k > (n - 1) * (n - 2) / 2){
        cout << -1 << endl;
        return 0;
    }
    cout << n - 1 + (n - 1) * (n - 2) / 2 - k << endl;
    rep(i, n - 1)cout << "1 " << i + 2 << endl;
    int cnt = 1;
    for(int i = 1; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(cnt > (n - 1) * (n - 2) / 2 - k)return 0;
            cout << i + 1 << ' ' << j + 1 << endl;
            cnt++;
        }
    }
}