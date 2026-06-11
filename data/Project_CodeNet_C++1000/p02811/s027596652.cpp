#include <iostream>
using namespace std;

int main() {
int K, X;
cin >> K >> X;

if (X <= (500 * K)){
    cout << "Yes" << '\n';
}
else{
    cout << "No" << '\n';
}
}