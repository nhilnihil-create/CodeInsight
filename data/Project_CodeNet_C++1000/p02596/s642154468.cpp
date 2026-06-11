#include <iostream>
using namespace std;

#include <vector>
int main(){
    int K,a = 7;cin >> K;
    for(int i=1; i<=K; i++) {
        a %= K;
        if(a==0){
            cout << i << endl;
            return 0;
        }
        a = 10*a+7;
    }
    cout << -1 << endl;
}