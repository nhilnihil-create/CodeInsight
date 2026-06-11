#include <iostream>

using namespace std;

int main(void) {
        int a[3];
        bool flag = true;
        int i = 0;

        for(int i = 0; i < 3; i++) {
                cin >> a[i]; 
        }

        while(i != 2) {
                if(a[i] >= a[i + 1]) {
                        flag = false;
                }
                i++;
        }
        
        if(flag == true) {
                cout << "Yes" << endl;
        } else {
                cout << "No" << endl;
        }
        return 0;
}