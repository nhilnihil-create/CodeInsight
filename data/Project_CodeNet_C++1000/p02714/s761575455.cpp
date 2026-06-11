#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    string S;
    int64_t ans,cnt;
    cin >> N >> S;
    
    map<char,int64_t> mp;
    for(int i=0;i<S.size();i++) {
        mp[S[i]]++;
    }
    
    if(mp.size() < 3){ 
        cout << "0\n";
        return 0;
    }
    ans = 1;
    for(auto m:mp) {
        ans *= m.second;
    }
    
    // 全部求めて引く？？？
    cnt = 0;
    for(int i=0;i<(N-2);i++) {
        for(int j=i+1;j<(N-1);j++) {
            if((j+j-i) >= N) break;
            if((S[i] != S[j]) && (S[i] != S[j+j-i]) && (S[j] != S[j+j-i])) cnt++;
        }
    }

    cout << ans -cnt << endl;
    return 0;
}
