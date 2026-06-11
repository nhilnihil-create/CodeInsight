#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int fal = min(A, B+C);
    int odg = fal - B;
    cout << C-odg << endl;
}