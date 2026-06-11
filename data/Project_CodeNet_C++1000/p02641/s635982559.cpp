#include<bits/stdc++.h>
using namespace std;
#define f(x,y,z) for(int x=y;x<z;++x)
int x, n, k;
map<int,bool> a;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> x >> n;
    if(!n) return cout << x << '\n', 0;
    f(i,0,n) {
        cin >> k;
        a[k] = true;
    }
    int i = 0;
    while(true) {
        if(!a[x-i]) return cout << x-i << '\n', 0;
        if(!a[x+i]) return cout << x+i << '\n', 0;
        ++i;
    }
}