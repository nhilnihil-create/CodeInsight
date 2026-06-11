#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

int main(){
    int x,y; cin >> x >> y;
    int ans = 0;
    vector<int> m{300000, 200000, 100000};
    if(x<=3) ans += m[x-1];
    if(y<=3) ans += m[y-1];
    if(ans==600000) ans += 400000;
    cout << ans << endl;
}