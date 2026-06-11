#include <iostream>

int main(){
    using namespace std;
    int k,x;
    cin >> k >> x;
    for (int i=x-k+1; i<x+k-1; i++) {
        cout << i << " ";
    }
    cout << x+k-1;
}