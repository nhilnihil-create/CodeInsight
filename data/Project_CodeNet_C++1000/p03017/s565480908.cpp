#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;
    bool possible = true;
    if (C < D){
        for (int i = A - 1; i < C - 1; i++){
            if (S[i] == '#' && S[i + 1] == '#') possible = false;
        }
        for (int i = B - 1; i < D - 1; i++){
            if (S[i] == '#' && S[i + 1] == '#') possible = false;
        }
    }
    else{
        int count = 0;
        for (int i = B - 1; i <= D - 1; i++){
            if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') count++;
        }
        for (int i = A - 1; i < C - 1; i++){
            if (S[i] == '#' && S[i + 1] == '#') possible = false;
        }
        for (int i = B - 1; i < D - 1; i++){
            if (S[i] == '#' && S[i + 1] == '#') possible = false;
        }
        if (count == 0) possible = false;
    }
    if (possible) cout << "Yes" << endl;
    else cout << "No" << endl;
}