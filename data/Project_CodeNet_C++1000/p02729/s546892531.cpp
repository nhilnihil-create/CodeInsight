#define _GLIBCXX_DEBUG
#include <iostream>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    n = (n-1)*n/2;
    m = (m-1)*m/2;
    cout << n+m << '\n';
    return 0;
}