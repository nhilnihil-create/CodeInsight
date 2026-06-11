#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int N, K;
    cin >> N >> K;
    vector<int> price(N);
    rep(i, N) cin >> price.at(i);

    sort(all(price));
    int ans=0;
    rep(i, K){
        ans += price.at(i);
    }
    cout << ans << endl;

    return 0;
}