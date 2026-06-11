#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans = "Yes";
    for(int i = 0; i < s.length(); i++){
        if(i % 2 == 0){
            if(!(s[i] == 'R' || s[i] == 'U' || s[i] == 'D')) ans = "No";
        }else{
            if(!(s[i] == 'L' || s[i] == 'U' || s[i] == 'D')) ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}