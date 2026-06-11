#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll ans[555][555];

int main(){

    ll N;
    cin >> N;
    for(ll i = 1; i <= 9; i++){
        for(ll j = 1; j < 555; ){
            vector<ll>A, B;
            for(ll k = 0; k < (1 << (i - 1)) && j < 555; k++, j++)A.push_back(j);
            for(ll k = 0; k < (1 << (i - 1)) && j < 555; k++, j++)B.push_back(j);
            for(ll k = 0; k < A.size(); k++){
                for(ll l = 0; l < B.size(); l++){
                    ans[A[k]][B[l]] = i;
                }
            }

        }
    }
    for(ll i = 1; i < N; i++){
        for(ll j = i + 1; j <= N; j++){
            cout << ans[i][j];
            if(j == N)cout << endl;
            else cout << " ";
        }
    }

    return 0;
}