#include <iostream>
using namespace std;

int main(){
    int k, x;
    cin >> k >> x;
    k--;
    for (int i = x - k; i <= x + k; i++) cout << i << ' ';
    cout << '\n';
}
