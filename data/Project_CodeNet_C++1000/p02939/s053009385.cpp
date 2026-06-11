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
    string S;
    cin >> S;
    S = " " + S;
    ll N = (int)S.size();
    int g[N];
    g[0] = 0, g[1] = 1;
    if(S.at(1) == S.at(2)) g[2] = 1;
    else g[2] = 2;
    for(int i = 3; i < N; i++){
        if(S.at(i) != S.at(i-1)){
            g[i] = g[i-1] + 1;
        }else{
            g[i] = g[i-3] + 2;
        }
    }
    cout << g[N-1] << endl;
    return 0;
}