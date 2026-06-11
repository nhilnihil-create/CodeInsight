#include <iostream>
using namespace std;

int main() {
    double s, x, m;
    cin >> s >> m >> x;
    if (s / x <= m){
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}
