#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> r(n);
    for(int i = 0; i < n; i++){
        int x,l;
        cin >> x >> l;
        r[i] = {x+l,x-l};
    }
    int ans = 1;
    sort(r.begin(),r.end());
    int now = r[0].first;
    for(int i = 1; i < n; i++){
        int nxt = r[i].second;
        if(nxt >= now){
            now = r[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}