#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;


int main(){
    string S; cin >> S;
    
    int ans = 0;
    string now = "", last = "";
    rep(i,S.size()){
        now += S[i];
        if(now != last){
            ans++;
            last = now; now ="";
        }
    }

    cout << ans << endl;
}
