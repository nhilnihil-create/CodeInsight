#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
        int a,b;
        int d,r;
        double f;
        cin >> a >> b;
        d = a / b;
        r = a % b;
        f = (double)a / b;
        cout << d << " " << r << " " << fixed << f << "\n";
        return 0;
}