#include<bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

#pragma GCC optimize("Ofast")



using namespace std;

bool is_integer( float x ){
    return floor(x) == x;
}
bool is_integer(double x){
    return floor(x) == x;
}


int main() {

    int n,m; cin >> n >> m;
    vector<pair<int,bool>> v(3);
    bool ans = true;
    int sum = 0;
    int a = 1;
    int ml = 1;
    for(int i = 1; i < n; i ++){
        ml *= 10;
    }
    if(m == 0){
        if(n == 1) cout << 0;
        else if(n == 2) cout << 10;
        else if(n == 3) cout << 100;
    }
    else {
        rep(i, m) {
            a = 1;
            int s, c;
            cin >> s >> c;
            if (n != 1 && (n + 1) - s >= n && c == 0) {
                ans = false;
                break;
            }
            for (int j = 1; j < n + 1 - s; j++) {
                a *= 10;
            }

            if ((sum / a) % 10 == 0) sum += a * c;
            else {
                if ((sum / a) % 10 != c) {
                    ans = false;
                    break;
                }
            }

        }

        if (ans){
            if(sum < ml){
                if(n == 1) cout << 0;
                else if(n == 2) cout << sum + 10;
                else if(n == 3) cout << sum + 100;
            }else {
                cout << sum;
            }
        }
        else cout << -1;
    }
    return 0;
}









