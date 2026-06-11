#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    if(N%10==3) {
        cout << "bon" << endl;
    } else if((N%10!=1 && N%10%2==1) || N%10==2 || N%10==4) {
        cout << "hon" << endl;
    } else {
        cout << "pon" << endl;
    }


    return 0;
    
}