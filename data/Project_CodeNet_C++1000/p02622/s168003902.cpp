#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    string S, T;
    cin >> S >> T;
    int ans = 0;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] != T[i]){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}