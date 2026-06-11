#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> S(N), T(N);
    for(int i = 0; i < N; ++i) {
        int x,l;
        cin >> x >> l;
        S[i] = x - l;
        T[i] = x + l;
    }

    vector<pair<int,int>> itv(N);
    for(int i = 0; i < N; ++i) {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv.begin(), itv.end());
    int ans = 0, t = -1e9+10;
    for(int i = 0; i < N; ++i){
        if(itv[i].second >= t) {
            ans++;
            t = itv[i].first;
        }
    }
    printf("%d\n", ans);
    return 0;
}