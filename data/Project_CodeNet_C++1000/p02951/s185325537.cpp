#include <iostream>
#include <algorithm>

using namespace std;

int main() {
   
    int A, B, C;
    cin >> A >> B >> C;
    int endA = min(A, B+C);
    int trans = endA - B;
    cout << C-trans << endl;
}