#include <iostream>
using namespace std;

#include <string>
int main(){
    string str; cin >> str;
    int ans = 0;
    if(str.at(1)=='R'){
        ans++;
        if(str.at(2)=='R')ans++;
        if(str.at(0)=='R')ans++;
    } else {
        if(str.at(0)=='R' || str.at(2)=='R') ans++;
    }
    cout << ans << endl;
}