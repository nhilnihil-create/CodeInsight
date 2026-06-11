#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e+09 + 7;

vector<int64_t> pow2(1e+5 + 10);
vector<int64_t> pow3(1e+5 + 10);
void pow () {
    int64_t num = 1,num2 = 1;
    for ( int64_t i = 0; i < 1e+5 + 10; ++i){
        pow2[i] = num2;
        pow3[i] = num;
        num2 = num2 * 2 % MOD;
        num = num * 3 % MOD;
    }
    return;
}

int main() {
    string L;
    cin >> L;
    
    pow();
    
    int64_t ans = 0;
    int64_t num1 = 0;
    for ( int64_t i = 0; i < L.size(); ++i){
        int64_t x =  L.at(i) - '0';
        if ( x == 1 ){
            int64_t restsize = L.size() - (i+1);
            ++num1;
            //cout << restsize << " " << pow3[restsize] << " " << num1 << " " << pow2[num1] << endl;
            ans = ( ans + pow3[restsize] * pow2[num1-1] ) % MOD;
        } /*else if ( i == L.size() - 1 ){
            ans = ( ans + pow2[num1] ) % MOD;
        }*/
    }
    
    cout << ( ans + pow2[num1] ) % MOD << endl;
    return 0;
}