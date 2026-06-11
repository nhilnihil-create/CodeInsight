#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    long long N,A,B;
    cin >> N >> A >> B;
    long long K =  N / (A+B);
    long long M = N % (A+B);
    long long ans = K * A + min(M,A);
    cout << ans << endl;
}
