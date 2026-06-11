#include <iostream>
#include <string>
using namespace std;
int main(void){
    string s;
    cin >> s;
    if(s[s.size()-1]=='s'){
        s.push_back('e');
        s.push_back('s');
    }else{
        s.push_back('s');
    }
    cout << s << endl;
    return 0;
}