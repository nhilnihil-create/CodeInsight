#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    string str, q, rep;
    int m, n, s, t;
    cin >> str;
    cin >> n;
    for(int i=0;i<n;i++) {
        s = 0;
        t = 0;
        cin >> q;
        if (q == "replace") {
            m = 1;
        } else if (q == "reverse") {
            m = 2;
        } else {
            m = 3;
        }
        switch(m) {
            case 1:
                cin >> s >> t;
                cin >> rep;
                for(int j=0;j<t-s+1;j++) {
                    str[s+j] = rep[j];
                }
                break;
            case 2:
                cin >> s >> t;
                rep = str;
                for(int j=0;j<t-s+1;j++) {
                    str[s+j] = rep[t-j];
                }
                break;
            case 3:
                cin >> s >> t;
                for(int j=0;j<t-s+1;j++) {
                    cout << str[s+j];
                }
                cout << endl;
                break;
        }
    }
}