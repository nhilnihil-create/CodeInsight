#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    A--; B--; C--; D--;

    if(C < D){
        ll c = 0;
        rep(i, B, D){
            if(S[i] == '#') c++;
            else c = 0; 
            if(c > 1){
                cout << "No" << endl;
                return 0;
            }
        }
        c = 0;
        rep(i, A, C){
            if(S[i] == '#') c++;
            else c = 0; 
            if(c > 1){
                cout << "No" << endl;
                return 0;
            }
        }
    }else{
        ll c = 0, mx = 0;
        rep(i, B-1, D+2){
            if(S[i] == '.') c++;
            else c = 0;
            mx = max(mx, c);
        }
        if(mx < 3){
            cout << "No" << endl;
            return 0;
        }
        c = 0;
        rep(i, A, C){
            if(S[i] == '#') c++;
            else c = 0;
            if(c > 1){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}