#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int i;
    string S;
    string T;
    cin >> S;
    cin >> T;

    if(T.length() - S.length() != 1){cout << "No" << endl;return 0;}
    else{
        for(i=0;i<S.length();i++){
            if(T[i] != S[i]){cout << "No" << endl;return 0;}
        }
    }
    cout << "Yes" << endl;

    return 0;
}
