#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a%2 == b%2) cout << (a+b)/2 << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}
