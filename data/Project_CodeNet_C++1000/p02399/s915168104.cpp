#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    int a, b;
    cin >> a >> b;
    cout << fixed;
    cout << setprecision(5);
    cout << a/b << " " << a%b << " " << (double)a/b << endl;
}

