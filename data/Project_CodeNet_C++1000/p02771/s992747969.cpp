#define _GLIBCXX_DEBUG
#include <iostream>
using namespace std;

int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    if(a==b && a!=c || b==c && b!=a || c==a && c!=b) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}