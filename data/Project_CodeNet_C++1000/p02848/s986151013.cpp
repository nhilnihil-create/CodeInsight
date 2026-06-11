#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>

int main() {
    ll N; cin >> N;
    string S; cin >> S;

    string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    rep(i,S.size()){
        rep(j,ALPHA.size()){
            if(S[i] == ALPHA[j]){
                S[i] = ALPHA[j + N];
                break;
            }
        }
    }
    cout << S << endl;
}