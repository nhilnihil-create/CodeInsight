#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s, p;
    cin >> s >> p;
    s = s + s;
//    cout << s << endl << p;
    if(s.find(p) == string::npos) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}