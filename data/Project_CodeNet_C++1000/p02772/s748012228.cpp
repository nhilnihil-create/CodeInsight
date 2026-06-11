#include <iostream>
using namespace std;

int main(void) {
    int len;
    cin >> len;
    for (int i = 0; i<len;i++) {
        int a;
        cin >> a;
        if( a % 2 == 0) {
            if(! (a % 3 == 0 || a % 5 == 0) ){
                cout << "DENIED" << endl;
                    return 0;
            }
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}
