#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int DP[2][13];

int main() {
    string S;
    cin >> S;
    
    int n = S.length();
    
    S = "?" + S;
    
    if(S[1] == '?') {
        for(int r = 0; r <= 9; r++) {
            DP[1][r] = 1;
        }
    } else {
        DP[1][S[1] - '0'] = 1;
    }
    
    for(int i = 2; i <= n; i++) {
        for(int r = 0; r < 13; r++) {
            DP[i % 2][r] = 0;
        }
        
        for(int r = 0; r < 13; r++) {
            if(S[i] != '?') {
                int x = (10 * r + S[i] - '0') % 13;
                DP[i % 2][x] += DP[(i + 1) % 2][r]; 
                DP[i % 2][x] %= MOD;
                continue;
            }
            
            for(int c = 0; c <= 9; c++) {
                int x = (10 * r + c) % 13;
                DP[i % 2][x] += DP[(i + 1) % 2][r];
                DP[i % 2][x] %= MOD;
            }
        }
    }
    
    
    cout << DP[n % 2][5];
    
    return 0;
}