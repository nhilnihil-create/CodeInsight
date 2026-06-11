#include <iostream>

using namespace std;

int main() {
    int edge1, edge2, equivalent, perimeter;
    cin >> edge1 >> edge2;
    equivalent = edge1 * edge2;
    perimeter = (edge1 + edge2) * 2;
    cout << equivalent << " " << perimeter << endl;
    return 0;
}