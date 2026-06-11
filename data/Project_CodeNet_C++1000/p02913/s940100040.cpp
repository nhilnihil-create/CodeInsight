#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)


void zAlgorithm(char s[], ll n, ll z[], ll ans[]){
    ll L = 0, R = 0;
    for(int i = 1; i < n; i++){
        if(i > R){
            L = R = i;
            while(R < n && s[R - L] == s[R]) 
            {
                R++;
            }
            z[i] = R - L;
            R--;
        }else{
            ll k = i - L;
            if(z[k] < R - i + 1){
                z[i] = z[k];
            }else{
                L = i;
                while(R < n && s[R - L] == s[R]){
                    R++;
                }
                z[i] = R - L; 
                R--;
            }
        }
    }
    for(ll i = 1; i < n; i++){
        if(z[i] > i){
            ans[i] = i;
        }else{
            ans[i] = z[i];
        }
    }
}

int main(){
    ll N;
    cin >> N;

    char s[N];
    cin >> s;

    ll z[N];
    ll ansA[N];
    ll ans = 0;
    rep(j, N){
        zAlgorithm(s + j, N - j, z, ansA);
        REP(i, N - 1){//cout << "j: " << j << ", i: " << i << ", z[i]: " << z[i] << ", ansA[i]" << ansA[i] << endl;
            if(ans < ansA[i]){
                ans = ansA[i];
            }
        }
    }

    cout << ans << endl;

    return 0;
}


