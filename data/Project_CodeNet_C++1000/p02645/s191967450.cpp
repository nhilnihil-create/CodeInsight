#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;
    string N = S.substr(0, 3);
    cout << N << endl;

    return 0;
}