#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
        long double r;
        long double const PI = 3.141592653589793238L;

        cin >> r;       
        long double area = PI * r * r;
        long double len = 2 * PI * r;
        cout << fixed << area << " ";
        cout << fixed << len << "\n";
        return 0;
}