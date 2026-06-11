#include <iostream>
using namespace std;
int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int buff = 0;
        cin >> buff;
        n = n-buff;
    }
    if(n < 0){
        cout << -1;
    } else{
        cout << n;
    }
    return 0;
}
