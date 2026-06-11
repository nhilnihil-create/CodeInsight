#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n % 2 == 0) cout << 0.5;
    else cout << (double)(n+1) / (double)(2*n);
    return 0;
}