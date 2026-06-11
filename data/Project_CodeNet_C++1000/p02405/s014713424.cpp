#include <iostream>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)

int h,w;
string s = "#.";

int main() {
    while(cin>>h>>w && h) {
        rep(i,h) {
            rep(j,w) {
                if(i%2 == 0) {
                    cout << s[j%2];
                } else {
                    cout << s[(j+1)%2];
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}