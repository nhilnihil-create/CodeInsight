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
    int N = (int)S.size();
    ll a[N+1] = {0};
    //左から、"<"の記号の成立を見る
    rep(i, N){
        if(S.at(i) == '<'){
            a[i+1] = max(a[i+1], a[i] + 1);
        }
    }
    //右から、">"の記号の成立を見る
    for(int i = N-1; i >= 0; i--){
        if(S.at(i) == '>'){
            a[i] = max(a[i], a[i+1] + 1);
        }
    }
    ll sum = 0;
    rep(i, N+1){
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}