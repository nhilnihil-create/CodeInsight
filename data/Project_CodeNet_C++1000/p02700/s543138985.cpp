#include <iostream>
using namespace std;
int main() {
    int a,b,c,d = 0;
    cin >> a>>b >> c >> d;
    for(;;){
        c = c - b;
        if(c <= 0){
            break;
        }
        a = a - d;
        if(a <= 0){
            break;
        }
    }
    if(a > c){
        cout << "Yes";
    } else{
        cout << "No";
    }
    return 0;
}
