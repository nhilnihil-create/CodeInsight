#include <iostream>
#include <algorithm>
using namespace std;


int main(){

    long a, b;
    cin >> a >> b;

    long z = max(a, b);
    long inc = max(a, b);

    while(true){
        if (z % a == 0 && z % b == 0) {
            break;
        }
        z += inc;
    }
    cout << z << endl;
}