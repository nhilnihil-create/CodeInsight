#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;

const long long mod = 1e9 + 7;

int main(){
    string s;
    cin >> s;
    long long n = s.size();
    vector<vector<long long> > d(n + 1, vector<long long>(13, 0));
    d[0][0] = 1;
    for(int i = 0; i < n; ++i){
        if(s[i] == '?'){
            for(int j = 0; j < 13; ++j)
                for(int k = 0; k < 10; ++k){
                    d[i + 1][(j * 10 + k) % 13] += d[i][j];
                    d[i + 1][(j * 10 + k) % 13] %= mod;
                }
        }
        else{
            for(int j = 0; j < 13; ++j){
                int k = s[i] - '0';
                d[i + 1][(j * 10 + k) % 13] += d[i][j];
                d[i + 1][(j * 10 + k) % 13] %= mod;
            }
        }
    }
    cout << d[n][5] % mod;
}
