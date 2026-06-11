#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int K;
    string S;
    cin >> K;
    cin >> S;

    int i;

    if(S.length() <= K){cout << S << endl; return 0;}
    else{
        for(i=0;i<K;i++){
            cout << S[i];
        }
        cout << "..." << endl;
        return 0;
    }

    return 0;
}
