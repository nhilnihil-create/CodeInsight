#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i=0; i<n; ++i){cin >> p[i];}
    int mi = INT32_MAX;
    int cnt = 0;
    for(int i=0; i<n; ++i){
        mi = min(p[i], mi);
        if(mi>=p[i]){cnt++;}
    }
    cout << cnt << endl;
    return 0;
}