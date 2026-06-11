#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    long a,b;
    while(cin >> a >> b){
        cout.precision(5);
        cout << a / b << " " << a % b <<  " "  << fixed << (double)a / (double)b << endl;
        return 0;
    }
}