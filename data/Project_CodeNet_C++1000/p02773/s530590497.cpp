#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<std::string> S){
    map<string, int> mp;
    for(auto s : S){
        mp[s] += 1;
    }
    int maxval = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        //cout << itr->first << " " << itr->second << endl;
        maxval = max(maxval, itr->second);
    }
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        if(itr->second == maxval) cout << itr->first << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::string> S(N);
    for(int i = 0 ; i < N ; i++){
        std::cin >> S[i];
    }
    solve(N, std::move(S));
    return 0;
}
