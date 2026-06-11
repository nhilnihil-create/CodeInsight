#include <iostream>

using namespace std;

int main()
{
    long int a,b;
    cin >> a >> b;

    long int resA,resB;
    double resC;
    resA = a / b;
    resB = a % b;
    resC = (double)a / (double)b;

    cout << resA << " " << resB << " " << fixed << resC << endl;

    return 0;
}