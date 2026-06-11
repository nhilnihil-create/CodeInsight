#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n; cin >> n;
    vector< pair<int,int> > vpii;
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        pair<int,int> p = {b,a};
        vpii.push_back(p);
    }
    sort(vpii.begin(), vpii.end());
    bool ok = 1;
    int curtime = 0;
    for(int i = 0; i < n; ++i){
        curtime += vpii[i].second;
        if(curtime > vpii[i].first){
            ok &= 0;
        }
    }
    puts(ok?"Yes\n":"No\n");
    return 0;  
}