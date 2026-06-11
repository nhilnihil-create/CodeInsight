//
//  main.cpp
//  T2020A

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    string S;
    cin >> S;
    string ans;
    for (int i=0; i<3; i++) {
        ans+=S.at(i);
    }
    cout << ans << endl;
    return 0;
}
