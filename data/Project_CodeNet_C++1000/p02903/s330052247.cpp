#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int h,w,a,b; cin >> h >> w >> a >> b;
    rep(i,h){
        rep(j,w){
            if((i<b && j<a) || (i>=b && j>=a)) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
}