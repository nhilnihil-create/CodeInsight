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
    int n, m; cin >> n >> m;
    int a = 1;
    int b = (m/2)*2+1;
    int c = b+1;
    int d = b+(m-(m/2))*2;
    rep(i,(m/2)) cout << a+i << " " << b-i << endl;
    rep(i,m-(m/2)) cout << c+i << " " << d-i << endl;
}