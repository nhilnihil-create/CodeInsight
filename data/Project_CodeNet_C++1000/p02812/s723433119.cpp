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

    ll count = 0;
    rep(i,N){
        if(S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C'){
            count ++;
        }
    }
    cout << count << endl;
}