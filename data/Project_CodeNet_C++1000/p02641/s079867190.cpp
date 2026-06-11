#include<bits/stdc++.h>
using namespace std;

int main(){
    int X, N;
    cin >> X >> N;
    vector<int> P(N);
    for(auto& p : P) cin >> p;
    int dx = 0;
    int ans = X;
    while(true){
        if(find(P.begin(), P.end(), X-dx) == P.end()){
            ans -= dx;
            break;
        }
        else if(find(P.begin(), P.end(), X+dx) == P.end()){
            ans += dx;
            break;
        }
        ++dx;
    }
    cout << ans << endl;
    return 0;
}