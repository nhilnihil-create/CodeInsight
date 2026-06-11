#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
string S;
ll N;




int main(){
    cin >> S;
    N = S.length();
    ll ans = 0;
    ll b = 0;
    for (ll i=N-1;i>=0;i--){
        ll k = S[i]-'0';
        if(k>5){
            if(b>=5){
                ans += 10 - k-1;
                b = k+1;
            }else{
                ans += 10 - k;
                b = k;
            }
        } else if(k==5){
            if(b>=5){
                ans += 10 - k-1;
                b = k+1;
            }else{
                ans += k;
                b = k;
            }
        }else{
            if(b>5){
                ans += k+1;
                b = k+1;
            }else{
                ans += k;
                b = k;
            }
        }
    }
    if(b>5){
        ans++;
    }
    cout << ans << endl;
}

