#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
int main(void){
    int N;
    cin >> N;
    
    vector<P> vp;
    
    for (int i=0; i<N; i++){
        int x, l;
        cin >> x >> l ;
        vp.push_back({x+l, x-l});
    }
    sort(vp.begin(), vp.end());
    
    int ans = 0;
    int t = -(1<<30);
    
    for (int i=0; i<N; i++){
        // cout << vp[i].second << " " << vp[i].first << endl;
        if(t <= vp[i].second){
            
            ans++;
            t = vp[i].first;
        }
    }
    cout << ans << endl;
}
