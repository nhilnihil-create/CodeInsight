#include <iostream>
#include <vector>
#include <string>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n,k;    cin >> n >> k;
    string s;   cin >> s;
    ll ans = 0;
    ll RL = 0;
    char r = s[n-1], l = s[0];
    rep(i, n-1){
        if(s[i] == 'R' && s[i+1] == 'L'){
            RL++;
        }
    }
    ans = n - RL*2;
    if(n == 1){
        ans = 0;
    }else{
        if(l == 'L')    ans--;
        if(r == 'R')    ans--;
    }
    if(l == 'R'){
        if(r == 'R'){
            if(RL <= k) ans += 2*RL;
            else        ans += 2*k;
        }else{
            if(RL <= k){
                if(RL == 1) ans += 1;
                else        ans += 2*(RL-1);
            }
            else        ans += 2*k;
        }
    }else{
        if(r == 'R'){
            if(RL < k)          ans += 2*RL + 1;
            else if(RL == k)    ans += 2*RL;
            else                ans += 2*k;
        }else{
            if(RL <= k)         ans += 2*RL;
            else                ans += 2*k;
        }
    }
    cout << ans << endl;
}
