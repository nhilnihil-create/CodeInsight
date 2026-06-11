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
    ll N, K, S;
    cin >> N >> K >> S;
    ll num = pow(10, 9);
    if(num == S){
        rep(i, K) cout << S << " ";
        rep(i, N-K) cout << 1 << " ";
        cout << endl;
    }else{
        rep(i, K) cout << S << " ";
        rep(i, N-K) cout << S+1 << " ";
        cout << endl;
    }
    return 0;
}