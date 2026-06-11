#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int n, m;
    cin >> n >> m;
    int sum=0, a;
    rep(i, m){
        cin >> a;
        sum += a;
    }

    if(sum > n) cout << -1 << endl;
    else cout << n-sum << endl;
    return 0;
}