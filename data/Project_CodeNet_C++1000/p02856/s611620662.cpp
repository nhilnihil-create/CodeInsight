#include <iostream>
using namespace std;
int main(void){
    int m;
    cin >> m;
    long long a = -1, b = 0;
    for(int i=0;i<m;i++){
        long long d, c;
        cin >> d >> c;
        a += c;
        b += d*c;
    }
    cout << a + (b-1)/9 << endl;
}
