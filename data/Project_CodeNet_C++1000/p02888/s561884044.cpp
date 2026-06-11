#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<int> L(N);
    rep(i, N) cin >> L[i];
    sort(L.begin(), L.end());
    int ans = 0;
    rep(a, N){
        for(int b = a + 1; b < N; b++){
            int count = 0;
            int ab = L[a] + L[b];
            int r = lower_bound(L.begin(), L.end(), ab) - L.begin();
            r--;
            count = r - b;
            ans += count;
        }
    }
    cout << ans << endl;
    return 0;
    
}