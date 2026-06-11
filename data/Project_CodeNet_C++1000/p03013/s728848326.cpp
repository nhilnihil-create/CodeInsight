#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll INF = 1e18;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> broken(M);
    for(int i=0; i<M; i++)cin >> broken.at(i);

    vector<ll> dp(N+1,0);
    dp.at(0) = 1;
    for(int i=1; i<=N; i++){
        if(binary_search(broken.begin(), broken.end(), i)){
            dp.at(i) = 0;
        }else{
            dp.at(i) += dp.at(i-1);
            if(i>1)dp.at(i) += dp.at(i-2);
        }

        dp.at(i) %= 1000000007;
    }

    // for(int i=0; i<=N; i++){
    //     cout << i << ": " << dp.at(i) << endl;
    // }

    cout << dp.at(N) << endl;
}