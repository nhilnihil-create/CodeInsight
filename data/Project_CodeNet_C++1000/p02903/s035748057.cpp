#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    for(int j = 0; j < h; j++) {
        for(int i = 0; i < w; i++) {
            if((i<a && j<b)||(i>=a && j>=b)) cout << "1";
            else cout << "0";
        }
        cout << "\n";
    }

    return 0;
}