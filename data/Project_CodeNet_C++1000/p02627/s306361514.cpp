#include <iostream>
#include <ctype.h>
using namespace std;
int main(){
    char a; cin >> a;
    cout << (isupper(a) ? "A\n" : "a\n");
    return 0;
}