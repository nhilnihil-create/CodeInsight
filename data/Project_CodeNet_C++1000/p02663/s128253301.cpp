/*
    Author - Param Kothari
    Ah shit, here we go again
*/

#include <bits/stdc++.h>
 
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair

typedef long long ll;
typedef long double ld;

void solve(){
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int res = 0;
    if(m2 >= m1){
        res = m2 - m1;
        res += (h2 - h1) * 60;
    }
    else{
        res += (m2 + 60 - m1);
        res += (h2 - h1 - 1) * 60;
    }
    cout << res - k << "\n";
    return;
}

int main(){
    IOS;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}