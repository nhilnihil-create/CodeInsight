#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main (void){
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    int sum = 0;
    if(A < K){
        sum += A;
        K -= A;
        if(B < K){
            K -= B;
            sum -= K;
        }
    }else{
        sum += K;
    }
    cout << sum << endl;
    return 0;
}