#include <iostream>
using namespace std;

int main(void){
    int N;
    long cnt;
    
    cnt = 0;
    cin >> N;
    
    for (int i = 1; i < N; i++){
        cnt = cnt + (N - 1) / i;
    }
    
    cout << cnt << endl;
}
