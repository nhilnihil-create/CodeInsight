#include <iostream>
using namespace std;
int main(void){
    
    int X;
    cin >> X;
    int N = X / 500;
    int M = X % 500;
    int A = M / 5;
    cout << N * 1000 + A * 5 << endl;
}
