#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
using namespace std;

int main(void){
    int k;
    cin >> k;
    string s;
    cin >> s;
    if(s.size() > k) s = s.substr(0, k) + "...";
    cout << s << '\n';
    return 0;
}