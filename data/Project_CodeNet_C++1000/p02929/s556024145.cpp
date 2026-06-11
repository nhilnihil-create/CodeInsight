#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<bool> L(2*N, false);
    int lr = 0;
    int tmp = 0;
    bool valid = true;
    for(int i = 0; i < 2*N; i++){
        char c = S[i];
        if(c == 'W'){
            if(tmp%2){
                lr++;
                L[i] = true;
                tmp++;
            }
            else{
                tmp--;
                if(lr > 0){
                    lr--;
                    L[i] = false;
                }
                else{
                    valid = false;
                }
            }
        }
        else{
            if(tmp%2){
                tmp--;
                if(lr > 0){
                    lr--;
                    L[i] = false;
                }
                else{
                    valid = false;
                }
            }
            else{
                lr++;
                L[i] = true;
                tmp++;
            }
        }
    }

    if(lr != 0)
        valid = false;

    if(!valid){
        cout << 0 << endl;
        return 0;
    }

    int nl = 0;
    ll ans = 1;
    for(auto&& l : L){
        if(l){
            nl++;
        }
        else{
            ans *= nl;
            ans %= MOD;
            nl--;
        }
    }

    for(int i = 1; i <= N; i++){
        ans *= i;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
