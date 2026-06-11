#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cassert>
#include<numeric>
typedef long long ll;
using namespace std;

int main(){
    ll A, B;   cin >> A >> B;
    ll aa = A;
    ll bb = B;
    int C;
    while(A%B>0){
        C = A%B;
        A = B;
        B = C;
    }
    cout << aa*bb/B;
}