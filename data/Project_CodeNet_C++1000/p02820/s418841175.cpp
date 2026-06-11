#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n, k; cin >> n >> k;
    ll R, S, P; cin >> R >> S >> P;
    string t; cin >> t;
    vector<char> memo;

    ll ans = 0;
    for(int i=0; i<n; i++){
        if(t[i]=='r'){
            if(i < k){
                memo.push_back('p');
                ans += P;
            }
            else if((memo[i-k] != 'p')){
                memo.push_back('p');
                ans += P;
            }else if(memo[i-k] == 'p'){
                memo.push_back('j'); // j : != r s p
            }
        }else if(t[i]=='s'){
            if(i < k){
                memo.push_back('r');
                ans += R;
            }
            else if((memo[i-k] != 'r')){
                memo.push_back('r');
                ans += R;
            }else if(memo[i-k] == 'r'){
                memo.push_back('j'); // j : != r s p
            }
        }else if(t[i]=='p'){
            if(i < k){
                memo.push_back('s');
                ans += S;
            }
            else if((memo[i-k] != 's')){
                memo.push_back('s');
                ans += S;
            }else if(memo[i-k] == 's'){
                memo.push_back('j'); // j : != r s p
            }
        }
    }
    cout << ans << endl;
    return 0;
}