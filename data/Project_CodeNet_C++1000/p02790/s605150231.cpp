#define _GLIBCXX_DEBUG
#include <iostream>
using namespace std;

int main(void){
    char a, b;
    cin >> a >> b;
    string as, bs;
    for(int i=0; i<b-'0'; i++) as += a;
    for(int i=0; i<a-'0'; i++) bs += b;
    cout << (as<bs ? as : bs) << '\n'; 
    return 0;
}