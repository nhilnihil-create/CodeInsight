#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int num = (int)(floor(log2(i)/log2(10)));
        if(num % 2 == 0){
            ++ans;
        }
    }
    return cout << ans << '\n', 0;
}