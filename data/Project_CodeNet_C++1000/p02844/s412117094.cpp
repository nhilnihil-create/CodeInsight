#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    ll N; cin >> N;
    string S; cin >> S;
    map<char, ll> M;
    for(auto ch : S) M[ch]++;
    ll ans = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                char s1 = 48+i, s2 = 48+j, s3 = 48+k;
                ll idx = 0;
                bool flag = false;
                for(; idx < N; idx++){
                    if(S[idx] == s1){idx++; break;}
                }
                for(;idx < N; idx++){
                    if(S[idx] == s2){idx++; break;}
                }
                for(; idx < N; idx++){
                    if(S[idx]== s3){
                        idx++; flag = true; break;
                    }
                }
                if(flag) ans++;

            }
        }
    }
    cout << ans << endl;


} 
