#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int R, S, P;
int func(char w){
    int val;
    if(w == 'r') val = R;
    if(w == 's') val = S;
    if(w == 'p') val = P;
    return val;
}

int main(){
    int N, K;
    cin >> N >> K;
    cin >> R >> S >> P;
    string T;
    string S;
    cin >> T;
    rep(i, N){
        if(T[i] == 'r') S.push_back('p');
        if(T[i] == 's') S.push_back('r');
        if(T[i] == 'p') S.push_back('s');
    }
    ll ans = 0;
    rep(i, N){
        if(i < K) ans += func(S[i]);
        else{
            if(S[i] == S[i-K]){
                S[i] = 'F';
            }else{
                ans += func(S[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}