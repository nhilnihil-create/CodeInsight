#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int N, D;
    cin >> N >> D;
    vector<double> x(N), y(N);
    rep(i, N) cin >> x.at(i) >> y.at(i);

    int ans=0;
    rep(i, N){
        if(sqrt(x.at(i)*x.at(i)+y.at(i)*y.at(i)) <= D) ans++;
    }
    cout << ans << endl;
 
    return 0;
}