#define _GLIBCXX_DEBUG
#include <iostream>
using namespace std;

int main(void){
    int n, r;
    cin >> n >> r;
    if(n<10) r += 100*(10-n);
    cout << r << '\n';
    return 0;
}