#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
using namespace std;

int main(void){
    int r=0, w, cnt=0;
    cin >> w;
    string s;
    cin >> s;
    w -= 1;
    while(r<w){
        if(s[r]=='R'){ r++; continue; }
        if(s[w]=='W'){ w--; continue; }
        cnt++;
        r++; w--;
    }
    cout << cnt << '\n';
    return 0;
}