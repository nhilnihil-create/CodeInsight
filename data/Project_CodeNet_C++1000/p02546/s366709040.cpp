#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    string s;
    cin >> s;
    
    int a = s.size() - 1;
    int b = s.at(a);
    
    if( b == 's'){
        cout << s << "es" << endl;
    }
    else{
        cout << s << 's' << endl;
    }
}