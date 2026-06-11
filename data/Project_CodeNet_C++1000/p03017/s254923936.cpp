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

int main(){
    int N;
    int A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S, T;
    S.push_back('.');
    cin >> T;
    S += T;
    if(C > D){
        bool is = false;
        for(int i = B; i <= D; i++){
            if(S[i-1] == '.' && S[i] == '.' && S[i+1] == '.') is = true;
        }
        if(!is){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = A+1; i<= C; i++){
        if(S[i] == '#' && S[i-1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = B+1; i <= D; i++){
        if(S[i] == '#' && S[i-1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}