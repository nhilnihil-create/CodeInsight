#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double a;
    if((N%2) == 1) {
        a = (double)(N/2+1) / N;
    } else {
        a = (double)(N/2) / N;
    }
    cout << a << endl;
    return 0;
}