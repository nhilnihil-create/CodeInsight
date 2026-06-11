#include <iostream>
using namespace std;

int main() {
    int d, t, s;
    double a;
    cin >> d >> t >> s;
    a = (double)d/s;
    if(a > (double)t){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}