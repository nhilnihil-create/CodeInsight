#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {
   

    int a,b;
    cin >> a >> b;
    cout << a/b << endl;
    cout << a%b << endl;
    cout << fixed << setprecision(20);
    cout << static_cast<long double>(a) / b << endl;

}

