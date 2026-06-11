#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n,k;
    cin >> n >> k;
    int R,S,P;
    cin >> R >> S >> P;
    string kyotai;
    cin >> kyotai;
    ll ans=0;
    rep(i,n){
        if(i>=k){
            if(kyotai[i] == kyotai[i-k]){
                kyotai[i] = '?';
            }
            else{
                if(kyotai[i] == 'r') ans += P;
                else if(kyotai[i] == 's') ans += R;
                else if (kyotai[i] == 'p') ans += S;
            }
        }
        else{
            if(kyotai[i] == 'r') ans += P;
            else if(kyotai[i] == 's') ans += R;
            else if (kyotai[i] == 'p') ans += S;
        }
    }
    cout << ans << endl;

}