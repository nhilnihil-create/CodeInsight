//url:
//problem name: Brick Break

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    if(N%2 != 0) cout << "No" << endl;
    else {
        for(int i = 0; i < N; i += 2) 
            if(S[i] != 'h' || S[i+1] != 'i') {
                cout << "No" << endl;
                return 0;
            }
        cout << "Yes" << endl;
    }
}