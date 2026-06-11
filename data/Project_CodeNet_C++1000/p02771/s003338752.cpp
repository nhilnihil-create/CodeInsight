#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if((A==B) && (A!=C)) {
        cout << "Yes" << endl;
    } else if((A==C) && (A!=B)) {
        cout << "Yes" << endl;
    } else if((B==C) && (A!=B)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}