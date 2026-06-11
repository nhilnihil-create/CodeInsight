#include <iostream>
#include <cctype>
#include <string>
#include <string.h>
using namespace std;
int main(){
    string a, b;
    cin >> a >> b;
    a = a + a ;
    if(a.find(b) != std::string::npos){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
