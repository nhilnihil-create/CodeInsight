#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N, ans = 0;;
    cin >> N;
    vector<string> S(N+1);
    unordered_map<string,long long> UM;
    for(int i = 1; i <= N; ++i) cin >> S[i];
    for(int i = 1; i <= N; ++i){
        sort(S[i].begin(), S[i].end());
        ++UM[S[i]];
    }
    for(auto itr = UM.begin(); itr != UM.end(); ++itr){
        ans += itr->second * (itr->second - 1.) / 2.;
    }
    cout << ans << endl;
    return 0;
}