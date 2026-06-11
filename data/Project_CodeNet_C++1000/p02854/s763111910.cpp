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
    int N;
    cin >> N;
    ll A[N+1];
    ll S[N+1];
    S[0] = 0;
    ll len = 0;
    for(int i = 1; i < N + 1; i++){
        cin >> A[i];
        len += A[i];
        S[i] = S[i-1] + A[i];
    }
    ll mid = len; //中心に一番近い切れ目の地点（0からの長さ）
    for(int i = 1; i < N + 1; i++){
        mid = min(mid, abs(S[i] - (len - S[i])));
    }
    
    cout << mid << endl;
    return 0;
}