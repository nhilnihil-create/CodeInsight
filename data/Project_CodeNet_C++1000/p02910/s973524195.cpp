#include <iostream>
#include <string>
using namespace std;
int main() {
    string S; cin>>S;
    bool flg=true;
    for (int i=0; i<S.length(); i++) {
        if (i%2 == 0) {
            if (S.at(i) == 'L') {
                flg=false;
                break;
            }
        } else {
            if (S.at(i) == 'R') {
                flg=false;
                break;
            }
        }
    }
    flg ? cout<<"Yes"<<endl : cout<<"No"<<endl;
    return 0;
}
