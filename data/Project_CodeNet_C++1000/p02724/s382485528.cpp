#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define INF 1e9
#define st string
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define fopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test(x) int t; cin >> t; while(t--) x();

//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};

void solve(){
    int x; cin >> x;
    if(x >= 500){
        int quin = x / 500;
        x -= quin*500;
        if(x >= 5 && x < 500){
            int cc = x / 5;
            cout << quin * 1000 + cc * 5;
            return;
        }
        cout << quin * 1000;
        return;
    }
    if(x < 500 && x >= 5){
        int cinc = x / 5;
        cout << 5 * cinc;
        return;
    }
    cout << 0 << endl;
}

int main(){
    fastio
    solve();
    return 0;
}

// 2000000000
// 20000000000
