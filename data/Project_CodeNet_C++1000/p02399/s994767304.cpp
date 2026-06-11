#include <iostream>
using namespace std;
int main(void){
    // Here your code !
    int a,b;
    cin >> a>>b;
    cout << a / b << " " << a % b << " ";
    printf("%lf", static_cast<double>(a) / static_cast<double>(b));
    cout << endl;
}