#include <iostream>

using namespace std;

int main(){
    int a, b, c, d, tk, ao;
    cin >> a >> b >> c >> d;

    tk = a / d + ((a % d) ? 1 : 0);
    ao = c / b + ((c % b) ? 1 : 0);

    if(tk >= ao){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}