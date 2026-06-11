#include <iostream>
#include <string>
using namespace std;


bool f(string s) {
    int n = s.size();
    bool flag = 1;
    for(int i = 0; i < n/2; i++) {
        if(s.at(i) != s.at(n-1-i)) flag = 0;
    }
    return flag;
}

int main(void){
    string s, s1 = "", s2 = "";
    cin >> s;
    int n = s.size();
    
    for(int i = 0; i < n/2; i++) {
        s1 += s.at(i);
        s2 += s.at(n-1-i);
    }
    
    if(f(s) == 1 && f(s1) == 1 && f(s2) == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
