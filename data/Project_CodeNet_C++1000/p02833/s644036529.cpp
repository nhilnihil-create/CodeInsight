#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N;
    cin >> N;
    if(N % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    N /= 2;
    long long cnt = 0;
    long long t = 5;
    while(N >= t){
        cnt += N / t;
        t *= 5;
    }
    cout << cnt << endl;
}