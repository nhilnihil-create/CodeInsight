#include <iostream>
using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    for(int i=1; i<1010; i++){
        if(a == i*8/100 && b == i*10/100){
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}