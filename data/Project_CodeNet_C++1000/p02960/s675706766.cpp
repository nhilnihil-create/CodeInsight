#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

using LONG = long long;
using LVEC = vector<long long>;

#define FOR(_i, s, e) for(_i = s; _i < e; ++_i)
#define FOR_INV(_i, s, e) for(_i = e - 1; _i >= s; --_i)

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


using pos = std::pair<LONG, LONG>;


int main(){
    string S;
    cin >> S;

    LONG i, j, k;
    LONG n = S.size();

    LVEC table[13];
    FOR(i, 0, 13){
        table[i].resize(n, 0);
    }

    if(S[n-1] == '?'){
        FOR(j, 0, 10){
            table[j][n-1] = 1;
        }
    }
    else{
        int num = S[n-1] - '0';
        table[num][n-1] = 1;
    }

    LONG mod_keta = 1;

    FOR_INV(i, 0, n-1){
        mod_keta *= 10;
        mod_keta %= 13;

        if(S[i] == '?'){
            FOR(j, 0, 10){
                int mod = (mod_keta * j) % 13;
                FOR(k, 0, 13){
                    int index = (k + mod) % 13;
                    table[index][i] += table[k][i + 1];
                    table[index][i] %= PRIME;
                }
            }
        }
        else{
            int num = S[i] - '0';
            int mod = (mod_keta * num) % 13;
            FOR(k, 0, 13){
                int index = (k + mod) % 13;
                table[index][i] += table[k][i + 1];
                table[index][i] %= PRIME;
            }
        }
    }

    cout << table[5][0] << endl;

}

