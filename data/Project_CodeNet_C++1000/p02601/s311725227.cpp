#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep2(i, n) for (int i = 0; i <= (int)(n); i++)

int main(void){
    int A,B,C,K;
    cin >> A >> B >> C >> K;

    bool flag = false;

    rep2(i,K){
        rep2(j,K){
            rep2(k,K){
                int AA = A * (1 << i); //あか
                int BB = B * (1 << j); //みどり
                int CC = C * (1 << k); //あお
                if(( BB > AA )&&( CC > BB )&&(i+j+k <= K)){
                    flag = true;
                   //break;
                } 
            }
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}