#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    // K^x <= N < K^x+1 のとき NはK進数でx+1桁
    cout << floor(log(N)/log(K))+1 << endl;
}
