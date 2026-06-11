#define _GLIBCXX_DEBUG
#include <iostream>
using namespace std;

int main(void){
    int k, x;
    cin >> k >> x;
    cout << (500*k>=x ? "Yes\n" : "No\n");
    return 0;
}