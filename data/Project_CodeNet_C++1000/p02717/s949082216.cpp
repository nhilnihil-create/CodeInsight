
#include <iostream>
#include <iomanip>
using namespace std;

void swap(int &X, int &Y) {
    int tmp = X;
    X = Y;
    Y = tmp;
} 

void Main() {
    // input
    int X, Y, Z;
    cin >> X >> Y >> Z;


    // translate
    swap(X, Y);
    swap(X, Z);


    // output
    cout << X << " " << Y << " " << Z << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
