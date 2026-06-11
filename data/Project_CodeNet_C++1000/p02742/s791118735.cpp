#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    ll h,w;
    cin >> h >> w;
    if(min(h,w)==1) cout << 1 << endl;
    else if(h%2==0) cout << h/2*w << endl;
    else if(w%2==0) cout << w/2*h << endl;
    else cout << h/2*w+w/2+1 << endl;
}
