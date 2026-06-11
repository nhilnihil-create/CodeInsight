#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];
#define int long long

signed main(){
    int N, A, B, C, D;
    string s;
    cin >> N >> A >> B >> C >> D >> s;
    s += '#';
    A--; B--; C--; D--;
    
    bool achievable = true;
    
    reps(i, A, max(C,D)-1){
        if(s[i]==s[i+1] && s[i] == '#') achievable = false;
    }
    
    if(D < C && achievable){
        achievable = false;
        reps(i, B, D){
            if(s[i-1]==s[i] && s[i]==s[i+1] && s[i]=='.'){
                achievable = true;
            }
        }
    }
    
    cout << (achievable ? "Yes" : "No") << endl;
}