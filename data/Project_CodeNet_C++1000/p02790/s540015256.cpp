#include <iostream>
using namespace std;
int main() {
    int n , m;
    cin >> n >> m;
    int x = min(n , m);
    int y = max(n , m);
    for(int i = 0 ; i < y ; i++){
        cout << x;
    }
    cout << endl;
}
