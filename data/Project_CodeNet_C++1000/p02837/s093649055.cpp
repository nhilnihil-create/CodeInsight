#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 12 + 5, mod = 1e9 + 7;

int a[N];
vector< pair<int, int> > v[N];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < a[i]; j++){
            int x, y;
            cin >> x >> y;
            x--;
            v[i].push_back({x, y});
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << n); i++){
        bool found = 0;
        for(int j = 0; j < n; j++){
            if((i >> j & 1) == 0) continue;
            for(auto k: v[j]){
                if(k.second != (i >> k.first & 1)) found = 1;
            }
            if(found) break;
        }
        if(!found)  ans = max(ans, __builtin_popcount(i));
    }
    cout << ans;


    return 0;
}
