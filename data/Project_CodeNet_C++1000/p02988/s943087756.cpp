#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n; cin >> n;
    vector<int> v(n);
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    for(int i = 1; i < n - 1; ++i){
        if((v[i] >= v[i - 1] && v[i] <= v[i + 1]) || (v[i] <= v[i - 1] && v[i] >= v[i + 1])){
            ++cnt;
        }
    }
    return cout << cnt << '\n',0;  
}