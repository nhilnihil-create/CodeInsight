#include <iostream>
#include <string>

using namespace std;

int main()
{
    int D, T, S;
    cin >> D >> T >> S;
    double time = D / (double)S;
    string result = T >= time ? "Yes" : "No";
    cout << result;
}