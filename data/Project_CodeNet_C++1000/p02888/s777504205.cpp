#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> L(N);
    for(int i = 0;i < N; ++i) cin >> L[i];
    sort(L.begin(), L.end());
    long long ans = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < i; ++j){
            int r = lower_bound(L.begin(), L.end(), L[i]+L[j]) - L.begin();
            int l = i+1;
            ans += r - l;
        }
    }
    cout << ans << endl;
    return 0;
}