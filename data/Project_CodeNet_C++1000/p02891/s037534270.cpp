#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;
 
int main(){
    string S, S_; ll K; cin >> S >> K;
    S_ = S;
    ll ans = 0;
    if((S.size() * K)%2 == 1){
        bool flag = true;
        for(int i = 1; i < S.size(); i++) if(S[i-1] != S[i]) flag = false;
        if(flag){
            cout << (ll)((ll)S.size() * K) / 2 << endl;
            return 0;
        }
    }
    for(int i = 1; i < S.size(); i++){
        if(S[i-1] == S[i]) { S[i] = '*'; ans++;}
    }
    ans = ans * K;
    if(S[0] == S[S.size()-1]) {
        string temp1={S[0]}, temp2 = {S[S.size()-1]};
        int i = 0, j = S.size()-1;
        //cout << S[i] << " " << S[i+1] << endl;
        while(S_[i] == S_[i+1]){temp1+=S[i+1]; i++;}
        while(S_[j] == S_[j-1]){temp2+=S[i+1]; j--;}
        if((temp1.size() + temp2.size()) % 2 == 0) ans+= K-1;
        //cout << temp1.size() << " " << temp2.size() << endl;
        //ans += K-1;
    }
    cout << ans << endl;
 
}