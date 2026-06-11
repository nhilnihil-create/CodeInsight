#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> X(N+1);
    int ans = 100*100*100, buf;
    for(int i = 1; i <= N; ++i) cin >> X[i];
    sort(X.begin(), X.end());
    for(int P = X[1]; P <= X[N]; ++P){
        buf = 0;
        for(int i = 1; i <= N; ++i){
            buf += pow(X[i]-P, 2);
        }
        ans = min(ans, buf);
    }
    cout << ans << endl;
    return 0;
}