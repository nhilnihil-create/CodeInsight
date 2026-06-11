#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<float> H){
    vector<float> dH(N-1, 0);
    for(int i = 0; i < N-1; ++i){
        if(H[i+1] - H[i] <= 0) dH[i] += 1;
    }
    //for(int i = 0; i < N; ++i) cout << dH[i] << endl;
    //cout << endl;
    vector<float> ans(N, 0);
    for(int i = 0; i < N-1; ++i){
        if(dH[i] > 0) ans[i+1] = ans[i] + dH[i];
        else ans[i+1] = 0;
    }
    //for(int i = 0; i < N; ++i) cout << ans[i] << endl;
    sort(ans.begin(), ans.end(), greater<float>());
    cout << ans[0] << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<float> H(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%fd",&H[i]);
    }
    solve(N, std::move(H));
    return 0;
}
