#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    // cinを高速にするためのおまじない
    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    long long int K,L=0;
    int a = -1;
    cin >> K;
    if(K%2 == 0){
        a = -1;
    }
    else{
        for(int i = 0; i<=K;i++){
            L = (L*10)%K+7;
            if(L%K == 0){
                a = i+1;
                break;
            }
        }
        
    }
    cout << a << endl;
    /////////////////////


    return 0;
}
