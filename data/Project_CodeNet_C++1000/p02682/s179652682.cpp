#define _GLIBCXX_DEBUG
#include <iostream>
using namespace std;

int main(void){
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k <= a) cout << k << '\n';
    else if(k <= a+b) cout << a << '\n';
    else cout << a-(k-a-b) << '\n';
    return 0;
}