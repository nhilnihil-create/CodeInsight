#define _GLIBCXX_DEBUG
#include <iostream>
using namespace std;

int main(void){
    int k, m=0;
    cin >> k;
    int a, b;
    cin >> a >> b;
    bool suc = false;
    while(m <= b){
        m += k;
        if(m>=a && m<=b){suc = true; break;}
    }
    if(suc) cout << "OK\n";
    else cout << "NG\n";
    return 0;
}