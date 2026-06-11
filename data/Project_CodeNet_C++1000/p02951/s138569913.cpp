#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int a, b, c; cin >> a >> b >> c;
    if(b - a + c >= 0){
        cout << b - a + c << '\n';
    }else{
        cout << 0 << '\n';
    } 
    return 0;
}