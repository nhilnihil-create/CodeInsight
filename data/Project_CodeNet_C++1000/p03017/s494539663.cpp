#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--; B--; C--; D--;
    string S;
    cin >> S;
    rep(i, A+1, max(C-1,D-1)){
        if(S[i] == '#' && S[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    
    if(D > C){
        cout << "Yes" << endl;
        return 0;
    }

    bool f = false;
    rep(i, B-1, min(D, C-1)){
        if(S[i] == '.' && S[i+1] == '.' && S[i+2] == '.'){
            f = true;
        }
    }

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}