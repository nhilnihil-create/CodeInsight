#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
using namespace std;

int main(void){
    int r = 0, w, cnt = 0;
    cin >> w;
    string s;
    cin >> s;
    w -= 1;
    while(r<w){
        while(r<w && s.at(r)=='R') r++;
        while(w>r && s.at(w)=='W') w--;
        if(w<=r) break;
        cnt++;
        r++;
        w--;
    }
    cout << cnt << '\n';
    return 0;
}