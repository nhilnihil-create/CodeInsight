#include <iostream>
using namespace std;

int main(){
        int input,h,m,s;
        cin >> input;
        s = input % 60;
        input = input / 60;
        m = input % 60;
        input = input / 60;
        h = input;
        cout << h << ":" << m << ":" << s << endl;
        return 0;
}