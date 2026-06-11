#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    string ans = "Good";
    char before = ' ';
    cin >> s;

    for (auto c : s){
        if ( before == c ) {
            ans = "Bad";
        } 
        before = c;
    }
    cout << ans << endl;

}