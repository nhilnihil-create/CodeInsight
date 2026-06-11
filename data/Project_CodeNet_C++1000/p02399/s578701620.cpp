#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    int a,b;
    double c;
    cin >> a >> b;
    cout << a/b <<  " " << a%b << " ";
    cout << fixed;
    cout << setprecision(6) << (double)a/b << endl;
    return 0;
}
