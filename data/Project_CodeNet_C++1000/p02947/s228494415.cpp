#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    int N;
    ll ans = 0;
    cin >> N;
    vector<string> S(N);
    map<string,ll> mp{};
    for(int i=0;i<N;i++) cin >> S[i];
    
    for(int i=0;i<N;i++){
        sort(S[i].begin(),S[i].end());
        if(mp.count(S[i]) == 0) {
             mp[S[i]] = 1;
        } else {
             mp[S[i]]++;
        }
    }
    
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
         if(itr->second > 1) {
             ans += (itr->second*(itr->second-1)/2);
         }
    }
    
    cout << ans << endl;
}